// Licensed to the .NET Foundation under one or more agreements.
// The .NET Foundation licenses this file to you under the MIT license.
// See the LICENSE file in the project root for more information.

using System.Linq;
using System.Text;
using Xunit;

namespace System.IO.Tests
{
    public class BinaryReaderTests
    {
        protected virtual Stream CreateStream()
        {
            return new MemoryStream();
        }

        [Fact]
        public void BinaryReader_DisposeTests()
        {
            // Disposing multiple times should not throw an exception
            using (Stream memStream = CreateStream())
            using (BinaryReader binaryReader = new BinaryReader(memStream))
            {
                binaryReader.Dispose();
                binaryReader.Dispose();
                binaryReader.Dispose();
            }
        }

        [Fact]
        public void BinaryReader_CloseTests()
        {
            // Closing multiple times should not throw an exception
            using (Stream memStream = CreateStream())
            using (BinaryReader binaryReader = new BinaryReader(memStream))
            {
                binaryReader.Close();
                binaryReader.Close();
                binaryReader.Close();
            }
        }

        [Fact]
        public void BinaryReader_DisposeTests_Negative()
        {
            using (Stream memStream = CreateStream())
            {
                BinaryReader binaryReader = new BinaryReader(memStream);
                binaryReader.Dispose();
                ValidateDisposedExceptions(binaryReader);
            }
        }

        [Fact]
        public void BinaryReader_CloseTests_Negative()
        {
            using (Stream memStream = CreateStream())
            {
                BinaryReader binaryReader = new BinaryReader(memStream);
                binaryReader.Close();
                ValidateDisposedExceptions(binaryReader);
            }
        }

        private void ValidateDisposedExceptions(BinaryReader binaryReader)
        {
            byte[] byteBuffer = new byte[10];
            char[] charBuffer = new char[10];

            Assert.Throws<ObjectDisposedException>(() => binaryReader.PeekChar());
            Assert.Throws<ObjectDisposedException>(() => binaryReader.Read());
            Assert.Throws<ObjectDisposedException>(() => binaryReader.Read(byteBuffer, 0, 1));
            Assert.Throws<ObjectDisposedException>(() => binaryReader.Read(charBuffer, 0, 1));
            Assert.Throws<ObjectDisposedException>(() => binaryReader.ReadBoolean());
            Assert.Throws<ObjectDisposedException>(() => binaryReader.ReadByte());
            Assert.Throws<ObjectDisposedException>(() => binaryReader.ReadBytes(1));
            Assert.Throws<ObjectDisposedException>(() => binaryReader.ReadChar());
            Assert.Throws<ObjectDisposedException>(() => binaryReader.ReadChars(1));
            Assert.Throws<ObjectDisposedException>(() => binaryReader.ReadDecimal());
            Assert.Throws<ObjectDisposedException>(() => binaryReader.ReadDouble());
            Assert.Throws<ObjectDisposedException>(() => binaryReader.ReadInt16());
            Assert.Throws<ObjectDisposedException>(() => binaryReader.ReadInt32());
            Assert.Throws<ObjectDisposedException>(() => binaryReader.ReadInt64());
            Assert.Throws<ObjectDisposedException>(() => binaryReader.ReadSByte());
            Assert.Throws<ObjectDisposedException>(() => binaryReader.ReadSingle());
            Assert.Throws<ObjectDisposedException>(() => binaryReader.ReadString());
            Assert.Throws<ObjectDisposedException>(() => binaryReader.ReadUInt16());
            Assert.Throws<ObjectDisposedException>(() => binaryReader.ReadUInt32());
            Assert.Throws<ObjectDisposedException>(() => binaryReader.ReadUInt64());
        }

        public class NegEncoding : UTF8Encoding
        {
            public override Decoder GetDecoder()
            {
                return new NegDecoder();
            }

            public class NegDecoder : Decoder
            {
                public override int GetCharCount(byte[] bytes, int index, int count)
                {
                    return 1;
                }

                public override int GetChars(byte[] bytes, int byteIndex, int byteCount, char[] chars, int charIndex)
                {
                    return -10000000;
                }
            }
        }

        [Fact]
        public void Read_InvalidEncoding()
        {
            using (var str = CreateStream())
            {
                byte[] memb = new byte[100];
                new Random(345).NextBytes(memb);
                str.Write(memb, 0, 100);
                str.Position = 0;

                using (var reader = new BinaryReader(str, new NegEncoding()))
                {
                    Assert.ThrowsAny<ArgumentException>(() => reader.Read(new char[10], 0, 10));
                }
            }
        }

        [Theory]
        [InlineData(100, 0, 100, 100, 100)]
        [InlineData(100, 25, 50, 100, 50)]
        [InlineData(50, 0, 100, 100, 50)]
        [InlineData(0, 0, 10, 10, 0)]
        public void Read_CharArray(int sourceSize, int index, int count, int destinationSize, int expectedReadLength)
        {
            using (var stream = CreateStream())
            {
                var source = new char[sourceSize];
                var random = new Random(345);

                for (int i = 0; i < sourceSize; i++)
                {
                    source[i] = (char)random.Next(0, 127);
                }

                stream.Write(Encoding.ASCII.GetBytes(source), 0, source.Length);
                stream.Position = 0;

                using (var reader = new BinaryReader(stream, Encoding.ASCII))
                {
                    var destination = new char[destinationSize];

                    int readCount = reader.Read(destination, index, count);

                    Assert.Equal(expectedReadLength, readCount);
                    Assert.Equal(source.Take(readCount), destination.Skip(index).Take(readCount));

                    // Make sure we didn't write past the end
                    Assert.True(destination.Skip(readCount + index).All(b => b == default(char)));
                }
            }
        }

        [Theory]
        [InlineData(new[] { 'h', 'e', 'l', 'l', 'o' }, 5, new[] { 'h', 'e', 'l', 'l', 'o' })]
        [InlineData(new[] { 'h', 'e', 'l', 'l', 'o' }, 8, new[] { 'h', 'e', 'l', 'l', 'o' })]
        [InlineData(new[] { 'h', 'e', '\0', '\0', 'o' }, 5, new[] { 'h', 'e', '\0', '\0', 'o' })]
        [InlineData(new[] { 'h', 'e', 'l', 'l', 'o' }, 0, new char[0])]
        [InlineData(new char[0], 5, new char[0])]
        public void ReadChars(char[] source, int readLength, char[] expected)
        {
            using (var stream = CreateStream())
            {
                stream.Write(Encoding.ASCII.GetBytes(source), 0, source.Length);
                stream.Position = 0;

                using (var reader = new BinaryReader(stream))
                {
                    var destination = reader.ReadChars(readLength);

                    Assert.Equal(expected, destination);
                }
            }
        }

        // ChunkingStream returns less than requested
        private sealed class ChunkingStream : MemoryStream
        {
            public override int Read(byte[] buffer, int offset, int count)
            {
                return base.Read(buffer, offset, count > 10 ? count - 3 : count);
            }

            public override int Read(Span<byte> destination)
            {
                return base.Read(destination.Length > 10 ? destination.Slice(0, destination.Length - 3) : destination);
            }
        }

        [Theory]
        [InlineData(false)]
        [InlineData(true)]
        public void ReadChars_OverReads(bool unicodeEncoding)
        {
            Encoding encoding = unicodeEncoding ? Encoding.Unicode : Encoding.UTF8;

            char[] data1 = "hello world \ud83d\ude03!".ToCharArray(); // 14 code points, 15 chars in UTF-16, 17 bytes in UTF-8
            uint data2 = 0xABCDEF01;

            using (Stream stream = new ChunkingStream())
            {
                using (BinaryWriter writer = new BinaryWriter(stream, encoding, leaveOpen: true))
                {
                    writer.Write(data1);
                    writer.Write(data2);
                }

                stream.Seek(0, SeekOrigin.Begin);
                using (BinaryReader reader = new BinaryReader(stream, encoding, leaveOpen: true))
                {
                    Assert.Equal(data1, reader.ReadChars(data1.Length));
                    Assert.Equal(data2, reader.ReadUInt32());
                }
            }
        }

        [Theory]
        [InlineData(100, 100, 100)]
        [InlineData(100, 50, 50)]
        [InlineData(50, 100, 50)]
        [InlineData(10, 0, 0)]
        [InlineData(0, 10, 0)]
        public void Read_ByteSpan(int sourceSize, int destinationSize, int expectedReadLength)
        {
            using (var stream = CreateStream())
            {
                var source = new byte[sourceSize];
                new Random(345).NextBytes(source);
                stream.Write(source, 0, source.Length);
                stream.Position = 0;

                using (var reader = new BinaryReader(stream))
                {
                    var destination = new byte[destinationSize];

                    int readCount = reader.Read(new Span<byte>(destination));

                    Assert.Equal(expectedReadLength, readCount);
                    Assert.Equal(source.Take(expectedReadLength), destination.Take(expectedReadLength));

                    // Make sure we didn't write past the end
                    Assert.True(destination.Skip(expectedReadLength).All(b => b == default(byte)));
                }
            }
        }

        [Fact]
        public void Read_ByteSpan_ThrowIfDisposed()
        {
            using (var memStream = CreateStream())
            {
                var binaryReader = new BinaryReader(memStream);
                binaryReader.Dispose();
                Assert.Throws<ObjectDisposedException>(() => binaryReader.Read(new Span<byte>()));
            }
        }

        [Theory]
        [InlineData(100, 100, 100)]
        [InlineData(100, 50, 50)]
        [InlineData(50, 100, 50)]
        [InlineData(10, 0, 0)]
        [InlineData(0, 10, 0)]
        public void Read_CharSpan(int sourceSize, int destinationSize, int expectedReadLength)
        {
            using (var stream = CreateStream())
            {
                var source = new char[sourceSize];
                var random = new Random(345);

                for (int i = 0; i < sourceSize; i++)
                {
                    source[i] = (char)random.Next(0, 127);
                }

                stream.Write(Encoding.ASCII.GetBytes(source), 0, source.Length);
                stream.Position = 0;

                using (var reader = new BinaryReader(stream, Encoding.ASCII))
                {
                    var destination = new char[destinationSize];

                    int readCount = reader.Read(new Span<char>(destination));

                    Assert.Equal(expectedReadLength, readCount);
                    Assert.Equal(source.Take(expectedReadLength), destination.Take(expectedReadLength));

                    // Make sure we didn't write past the end
                    Assert.True(destination.Skip(expectedReadLength).All(b => b == default(char)));
                }
            }
        }

        [Fact]
        public void Read_CharSpan_ThrowIfDisposed()
        {
            using (var memStream = CreateStream())
            {
                var binaryReader = new BinaryReader(memStream);
                binaryReader.Dispose();
                Assert.Throws<ObjectDisposedException>(() => binaryReader.Read(new Span<char>()));
            }
        }
    }
}
