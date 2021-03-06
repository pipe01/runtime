// Copyright (c) Microsoft. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

#pragma once

#if defined(_MSC_VER)
#define MCC_API extern "C" __declspec(dllexport)
#define WINAPI __stdcall
#else
#define MCC_API extern "C" __attribute__((visibility("default")))
#define WINAPI
#ifdef BIT64
#define __int64     long
#else // BIT64
#define __int64     long long
#endif // BIT64

#define __int32     int
#define __int16     short int
#define __int8      char        // assumes char is signed

#endif 

// ---------------------------------
// VType0
// ---------------------------------
struct VType0 {
    int		count;
    __int64	sum;
    double	average;
    __int64	dummy1;
    double	dummy2;
};


// ---------------------------------
// VType1
// ---------------------------------
struct VType1 {
    float count;
    float sum;
    float average;
    float count1;
    float sum1;
    float average1;
    float count2;
    float sum2;
    float average2;
    float count3;
    float sum3;
    float average3;
    float count4;
    float sum4;
    float average4;
    float count5;
    float sum5;
    float average5;
};


// ---------------------------------
// VType3
// ---------------------------------
struct VType3 {
    float f1;
    float f2;
    float f3;
    float f4;
    float f5;
    float f6;
    float f7;
    float f8;

    void reset() {
        f1 = 0;
        f2 = 0;
        f3 = 0;
        f4 = 0;
        f5 = 0;
        f6 = 0;
        f7 = 0;
        f8 = 0;
    }

    void add(VType3 val) {
        f1 += val.f1;
        f2 += val.f2;
        f3 += val.f3;
        f4 += val.f4;
        f5 += val.f5;
        f6 += val.f6;
        f7 += val.f7;
        f8 += val.f8;
    }
};


// ---------------------------------
// VType5
// ---------------------------------
struct VType5 {
    __int64 f1;
    __int64 f2;
    __int64 f3;
    __int64 f4;
    __int64 f5;
    __int64 f6;
    __int64 f7;
    __int64 f8;
    __int64 f9;
    __int64 f10;
    __int64 f11;
    __int64 f12;
    __int64 f13;
    __int64 f14;
    __int64 f15;
    __int64 f16;
    __int64 f17;
    __int64 f18;

    void reset() {
        f1 = 0;
        f2 = 0;
        f3 = 0;
        f4 = 0;
        f5 = 0;
        f6 = 0;
        f7 = 0;
        f8 = 0;
        f9 = 0;
        f10 = 0;
        f11 = 0;
        f12 = 0;
        f13 = 0;
        f14 = 0;
        f15 = 0;
        f16 = 0;
        f17 = 0;
        f18 = 0;
    }

    void add(VType5 val) {
        f1 += val.f1;
        f2 += val.f2;
        f3 += val.f3;
        f4 += val.f4;
        f5 += val.f5;
        f6 += val.f6;
        f7 += val.f7;
        f8 += val.f8;
        f9 += val.f9;
        f10 += val.f10;
        f11 += val.f11;
        f12 += val.f12;
        f13 += val.f13;
        f14 += val.f14;
        f15 += val.f15;
        f16 += val.f16;
        f17 += val.f17;
        f18 += val.f18;
    }
};


// ---------------------------------
// VType6
// ---------------------------------
struct VType6 {
    double f1;
    double f2;
    double f3;
    double f4;
    double f5;
    double f6;
    double f7;
    double f8;
    double f9;
    double f10;
    double f11;
    double f12;
    double f13;
    double f14;
    double f15;
    double f16;
    double f17;
    double f18;
    double f19;
    double f20;
    double f21;
    double f22;
    double f23;
    double f24;
    double f25;
    double f26;
    double f27;
    double f28;
    double f29;

    void reset() {
        f1 = 0;
        f2 = 0;
        f3 = 0;
        f4 = 0;
        f5 = 0;
        f6 = 0;
        f7 = 0;
        f8 = 0;
        f9 = 0;
        f10 = 0;
        f11 = 0;
        f12 = 0;
        f13 = 0;
        f14 = 0;
        f15 = 0;
        f16 = 0;
        f17 = 0;
        f18 = 0;
        f19 = 0;
        f20 = 0;
        f21 = 0;
        f22 = 0;
        f23 = 0;
        f24 = 0;
        f25 = 0;
        f26 = 0;
        f27 = 0;
        f28 = 0;
        f29 = 0;
    }

    void add(VType6 val) {
        f1 += val.f1;
        f2 += val.f2;
        f3 += val.f3;
        f4 += val.f4;
        f5 += val.f5;
        f6 += val.f6;
        f7 += val.f7;
        f8 += val.f8;
        f9 += val.f9;
        f10 += val.f10;
        f11 += val.f11;
        f12 += val.f12;
        f13 += val.f13;
        f14 += val.f14;
        f15 += val.f15;
        f16 += val.f16;
        f17 += val.f17;
        f18 += val.f18;
        f19 += val.f19;
        f20 += val.f20;
        f21 += val.f21;
        f22 += val.f22;
        f23 += val.f23;
        f24 += val.f24;
        f25 += val.f25;
        f26 += val.f26;
        f27 += val.f27;
        f28 += val.f28;
        f29 += val.f29;
    }
};


// ---------------------------------
// VType7
// ---------------------------------
struct VType7 {
    double f1;
    double f2;
    double f3;
    double f4;
    double f5;
    double f6;
    double f7;
    double f8;
    double f9;
    double f10;
    double f11;
    double f12;
    double f13;
    double f14;
    double f15;
    double f16;
    double f17;
    double f18;
    double f19;
    double f20;
    double f21;
    double f22;
    double f23;
    double f24;
    double f25;
    double f26;
    double f27;
    double f28;
    double f29;
    double f30;
    double f31;
    double f32;
    double f33;
    double f34;
    double f35;
    double f36;
    double f37;
    double f38;
    double f39;
    double f40;
    double f41;
    double f42;
    double f43;
    double f44;
    double f45;
    double f46;
    double f47;
    double f48;
    double f49;
    double f50;
    double f51;
    double f52;
    double f53;
    double f54;
    double f55;
    double f56;
    double f57;
    double f58;
    double f59;
    double f60;
    double f61;
    double f62;
    double f63;
    double f64;
    double f65;
    double f66;
    double f67;
    double f68;
    double f69;
    double f70;
    double f71;
    double f72;
    double f73;
    double f74;
    double f75;
    double f76;
    double f77;
    double f78;
    double f79;
    double f80;
    double f81;
    double f82;
    double f83;
    double f84;
    double f85;
    double f86;
    double f87;
    double f88;
    double f89;
    double f90;
    double f91;
    double f92;
    double f93;
    double f94;
    double f95;
    double f96;
    double f97;
    double f98;
    double f99;
    double f100;
    double f101;
    double f102;
    double f103;
    double f104;
    double f105;
    double f106;
    double f107;
    double f108;
    double f109;
    double f110;
    double f111;
    double f112;
    double f113;
    double f114;
    double f115;
    double f116;
    double f117;
    double f118;
    double f119;
    double f120;
    double f121;
    double f122;
    double f123;
    double f124;
    double f125;
    double f126;
    double f127;
    double f128;
    double f129;
    double f130;
    double f131;
    double f132;
    double f133;
    double f134;
    double f135;
    double f136;
    double f137;
    double f138;
    double f139;
    double f140;
    double f141;
    double f142;
    double f143;
    double f144;
    double f145;
    double f146;
    double f147;
    double f148;
    double f149;
    double f150;
    double f151;
    double f152;
    double f153;
    double f154;
    double f155;
    double f156;
    double f157;
    double f158;
    double f159;
    double f160;
    double f161;
    double f162;
    double f163;
    double f164;
    double f165;
    double f166;
    double f167;
    double f168;
    double f169;
    double f170;
    double f171;
    double f172;
    double f173;
    double f174;
    double f175;
    double f176;
    double f177;
    double f178;
    double f179;
    double f180;
    double f181;
    double f182;
    double f183;
    double f184;
    double f185;
    double f186;
    double f187;
    double f188;
    double f189;
    double f190;
    double f191;
    double f192;
    double f193;
    double f194;
    double f195;
    double f196;
    double f197;
    double f198;
    double f199;
    double f200;
    double f201;
    double f202;
    double f203;
    double f204;
    double f205;
    double f206;
    double f207;
    double f208;
    double f209;
    double f210;
    double f211;
    double f212;
    double f213;
    double f214;
    double f215;
    double f216;
    double f217;
    double f218;
    double f219;
    double f220;
    double f221;
    double f222;
    double f223;
    double f224;
    double f225;
    double f226;
    double f227;
    double f228;
    double f229;
    double f230;
    double f231;
    double f232;
    double f233;
    double f234;
    double f235;
    double f236;
    double f237;
    double f238;
    double f239;
    double f240;
    double f241;
    double f242;
    double f243;
    double f244;
    double f245;
    double f246;
    double f247;
    double f248;
    double f249;
    double f250;
    double f251;
    double f252;
    double f253;
    double f254;
    double f255;
    double f256;
    double f257;

    void reset() {
        f1 = (double)0.0;
        f2 = (double)0.0;
        f3 = (double)0.0;
        f4 = (double)0.0;
        f5 = (double)0.0;
        f6 = (double)0.0;
        f7 = (double)0.0;
        f8 = (double)0.0;
        f9 = (double)0.0;
        f10 = (double)0.0;
        f11 = (double)0.0;
        f12 = (double)0.0;
        f13 = (double)0.0;
        f14 = (double)0.0;
        f15 = (double)0.0;
        f16 = (double)0.0;
        f17 = (double)0.0;
        f18 = (double)0.0;
        f19 = (double)0.0;
        f20 = (double)0.0;
        f21 = (double)0.0;
        f22 = (double)0.0;
        f23 = (double)0.0;
        f24 = (double)0.0;
        f25 = (double)0.0;
        f26 = (double)0.0;
        f27 = (double)0.0;
        f28 = (double)0.0;
        f29 = (double)0.0;
        f30 = (double)0.0;
        f31 = (double)0.0;
        f32 = (double)0.0;
        f33 = (double)0.0;
        f34 = (double)0.0;
        f35 = (double)0.0;
        f36 = (double)0.0;
        f37 = (double)0.0;
        f38 = (double)0.0;
        f39 = (double)0.0;
        f40 = (double)0.0;
        f41 = (double)0.0;
        f42 = (double)0.0;
        f43 = (double)0.0;
        f44 = (double)0.0;
        f45 = (double)0.0;
        f46 = (double)0.0;
        f47 = (double)0.0;
        f48 = (double)0.0;
        f49 = (double)0.0;
        f50 = (double)0.0;
        f51 = (double)0.0;
        f52 = (double)0.0;
        f53 = (double)0.0;
        f54 = (double)0.0;
        f55 = (double)0.0;
        f56 = (double)0.0;
        f57 = (double)0.0;
        f58 = (double)0.0;
        f59 = (double)0.0;
        f60 = (double)0.0;
        f61 = (double)0.0;
        f62 = (double)0.0;
        f63 = (double)0.0;
        f64 = (double)0.0;
        f65 = (double)0.0;
        f66 = (double)0.0;
        f67 = (double)0.0;
        f68 = (double)0.0;
        f69 = (double)0.0;
        f70 = (double)0.0;
        f71 = (double)0.0;
        f72 = (double)0.0;
        f73 = (double)0.0;
        f74 = (double)0.0;
        f75 = (double)0.0;
        f76 = (double)0.0;
        f77 = (double)0.0;
        f78 = (double)0.0;
        f79 = (double)0.0;
        f80 = (double)0.0;
        f81 = (double)0.0;
        f82 = (double)0.0;
        f83 = (double)0.0;
        f84 = (double)0.0;
        f85 = (double)0.0;
        f86 = (double)0.0;
        f87 = (double)0.0;
        f88 = (double)0.0;
        f89 = (double)0.0;
        f90 = (double)0.0;
        f91 = (double)0.0;
        f92 = (double)0.0;
        f93 = (double)0.0;
        f94 = (double)0.0;
        f95 = (double)0.0;
        f96 = (double)0.0;
        f97 = (double)0.0;
        f98 = (double)0.0;
        f99 = (double)0.0;
        f100 = (double)0.0;
        f101 = (double)0.0;
        f102 = (double)0.0;
        f103 = (double)0.0;
        f104 = (double)0.0;
        f105 = (double)0.0;
        f106 = (double)0.0;
        f107 = (double)0.0;
        f108 = (double)0.0;
        f109 = (double)0.0;
        f110 = (double)0.0;
        f111 = (double)0.0;
        f112 = (double)0.0;
        f113 = (double)0.0;
        f114 = (double)0.0;
        f115 = (double)0.0;
        f116 = (double)0.0;
        f117 = (double)0.0;
        f118 = (double)0.0;
        f119 = (double)0.0;
        f120 = (double)0.0;
        f121 = (double)0.0;
        f122 = (double)0.0;
        f123 = (double)0.0;
        f124 = (double)0.0;
        f125 = (double)0.0;
        f126 = (double)0.0;
        f127 = (double)0.0;
        f128 = (double)0.0;
        f129 = (double)0.0;
        f130 = (double)0.0;
        f131 = (double)0.0;
        f132 = (double)0.0;
        f133 = (double)0.0;
        f134 = (double)0.0;
        f135 = (double)0.0;
        f136 = (double)0.0;
        f137 = (double)0.0;
        f138 = (double)0.0;
        f139 = (double)0.0;
        f140 = (double)0.0;
        f141 = (double)0.0;
        f142 = (double)0.0;
        f143 = (double)0.0;
        f144 = (double)0.0;
        f145 = (double)0.0;
        f146 = (double)0.0;
        f147 = (double)0.0;
        f148 = (double)0.0;
        f149 = (double)0.0;
        f150 = (double)0.0;
        f151 = (double)0.0;
        f152 = (double)0.0;
        f153 = (double)0.0;
        f154 = (double)0.0;
        f155 = (double)0.0;
        f156 = (double)0.0;
        f157 = (double)0.0;
        f158 = (double)0.0;
        f159 = (double)0.0;
        f160 = (double)0.0;
        f161 = (double)0.0;
        f162 = (double)0.0;
        f163 = (double)0.0;
        f164 = (double)0.0;
        f165 = (double)0.0;
        f166 = (double)0.0;
        f167 = (double)0.0;
        f168 = (double)0.0;
        f169 = (double)0.0;
        f170 = (double)0.0;
        f171 = (double)0.0;
        f172 = (double)0.0;
        f173 = (double)0.0;
        f174 = (double)0.0;
        f175 = (double)0.0;
        f176 = (double)0.0;
        f177 = (double)0.0;
        f178 = (double)0.0;
        f179 = (double)0.0;
        f180 = (double)0.0;
        f181 = (double)0.0;
        f182 = (double)0.0;
        f183 = (double)0.0;
        f184 = (double)0.0;
        f185 = (double)0.0;
        f186 = (double)0.0;
        f187 = (double)0.0;
        f188 = (double)0.0;
        f189 = (double)0.0;
        f190 = (double)0.0;
        f191 = (double)0.0;
        f192 = (double)0.0;
        f193 = (double)0.0;
        f194 = (double)0.0;
        f195 = (double)0.0;
        f196 = (double)0.0;
        f197 = (double)0.0;
        f198 = (double)0.0;
        f199 = (double)0.0;
        f200 = (double)0.0;
        f201 = (double)0.0;
        f202 = (double)0.0;
        f203 = (double)0.0;
        f204 = (double)0.0;
        f205 = (double)0.0;
        f206 = (double)0.0;
        f207 = (double)0.0;
        f208 = (double)0.0;
        f209 = (double)0.0;
        f210 = (double)0.0;
        f211 = (double)0.0;
        f212 = (double)0.0;
        f213 = (double)0.0;
        f214 = (double)0.0;
        f215 = (double)0.0;
        f216 = (double)0.0;
        f217 = (double)0.0;
        f218 = (double)0.0;
        f219 = (double)0.0;
        f220 = (double)0.0;
        f221 = (double)0.0;
        f222 = (double)0.0;
        f223 = (double)0.0;
        f224 = (double)0.0;
        f225 = (double)0.0;
        f226 = (double)0.0;
        f227 = (double)0.0;
        f228 = (double)0.0;
        f229 = (double)0.0;
        f230 = (double)0.0;
        f231 = (double)0.0;
        f232 = (double)0.0;
        f233 = (double)0.0;
        f234 = (double)0.0;
        f235 = (double)0.0;
        f236 = (double)0.0;
        f237 = (double)0.0;
        f238 = (double)0.0;
        f239 = (double)0.0;
        f240 = (double)0.0;
        f241 = (double)0.0;
        f242 = (double)0.0;
        f243 = (double)0.0;
        f244 = (double)0.0;
        f245 = (double)0.0;
        f246 = (double)0.0;
        f247 = (double)0.0;
        f248 = (double)0.0;
        f249 = (double)0.0;
        f250 = (double)0.0;
        f251 = (double)0.0;
        f252 = (double)0.0;
        f253 = (double)0.0;
        f254 = (double)0.0;
        f255 = (double)0.0;
        f256 = (double)0.0;
        f257 = (double)0.0;
    }

    void add(VType7 val) {
        f1 += val.f1;
        f2 += val.f2;
        f3 += val.f3;
        f4 += val.f4;
        f5 += val.f5;
        f6 += val.f6;
        f7 += val.f7;
        f8 += val.f8;
        f9 += val.f9;
        f10 += val.f10;
        f11 += val.f11;
        f12 += val.f12;
        f13 += val.f13;
        f14 += val.f14;
        f15 += val.f15;
        f16 += val.f16;
        f17 += val.f17;
        f18 += val.f18;
        f19 += val.f19;
        f20 += val.f20;
        f21 += val.f21;
        f22 += val.f22;
        f23 += val.f23;
        f24 += val.f24;
        f25 += val.f25;
        f26 += val.f26;
        f27 += val.f27;
        f28 += val.f28;
        f29 += val.f29;
        f30 += val.f30;
        f31 += val.f31;
        f32 += val.f32;
        f33 += val.f33;
        f34 += val.f34;
        f35 += val.f35;
        f36 += val.f36;
        f37 += val.f37;
        f38 += val.f38;
        f39 += val.f39;
        f40 += val.f40;
        f41 += val.f41;
        f42 += val.f42;
        f43 += val.f43;
        f44 += val.f44;
        f45 += val.f45;
        f46 += val.f46;
        f47 += val.f47;
        f48 += val.f48;
        f49 += val.f49;
        f50 += val.f50;
        f51 += val.f51;
        f52 += val.f52;
        f53 += val.f53;
        f54 += val.f54;
        f55 += val.f55;
        f56 += val.f56;
        f57 += val.f57;
        f58 += val.f58;
        f59 += val.f59;
        f60 += val.f60;
        f61 += val.f61;
        f62 += val.f62;
        f63 += val.f63;
        f64 += val.f64;
        f65 += val.f65;
        f66 += val.f66;
        f67 += val.f67;
        f68 += val.f68;
        f69 += val.f69;
        f70 += val.f70;
        f71 += val.f71;
        f72 += val.f72;
        f73 += val.f73;
        f74 += val.f74;
        f75 += val.f75;
        f76 += val.f76;
        f77 += val.f77;
        f78 += val.f78;
        f79 += val.f79;
        f80 += val.f80;
        f81 += val.f81;
        f82 += val.f82;
        f83 += val.f83;
        f84 += val.f84;
        f85 += val.f85;
        f86 += val.f86;
        f87 += val.f87;
        f88 += val.f88;
        f89 += val.f89;
        f90 += val.f90;
        f91 += val.f91;
        f92 += val.f92;
        f93 += val.f93;
        f94 += val.f94;
        f95 += val.f95;
        f96 += val.f96;
        f97 += val.f97;
        f98 += val.f98;
        f99 += val.f99;
        f100 += val.f100;
        f101 += val.f101;
        f102 += val.f102;
        f103 += val.f103;
        f104 += val.f104;
        f105 += val.f105;
        f106 += val.f106;
        f107 += val.f107;
        f108 += val.f108;
        f109 += val.f109;
        f110 += val.f110;
        f111 += val.f111;
        f112 += val.f112;
        f113 += val.f113;
        f114 += val.f114;
        f115 += val.f115;
        f116 += val.f116;
        f117 += val.f117;
        f118 += val.f118;
        f119 += val.f119;
        f120 += val.f120;
        f121 += val.f121;
        f122 += val.f122;
        f123 += val.f123;
        f124 += val.f124;
        f125 += val.f125;
        f126 += val.f126;
        f127 += val.f127;
        f128 += val.f128;
        f129 += val.f129;
        f130 += val.f130;
        f131 += val.f131;
        f132 += val.f132;
        f133 += val.f133;
        f134 += val.f134;
        f135 += val.f135;
        f136 += val.f136;
        f137 += val.f137;
        f138 += val.f138;
        f139 += val.f139;
        f140 += val.f140;
        f141 += val.f141;
        f142 += val.f142;
        f143 += val.f143;
        f144 += val.f144;
        f145 += val.f145;
        f146 += val.f146;
        f147 += val.f147;
        f148 += val.f148;
        f149 += val.f149;
        f150 += val.f150;
        f151 += val.f151;
        f152 += val.f152;
        f153 += val.f153;
        f154 += val.f154;
        f155 += val.f155;
        f156 += val.f156;
        f157 += val.f157;
        f158 += val.f158;
        f159 += val.f159;
        f160 += val.f160;
        f161 += val.f161;
        f162 += val.f162;
        f163 += val.f163;
        f164 += val.f164;
        f165 += val.f165;
        f166 += val.f166;
        f167 += val.f167;
        f168 += val.f168;
        f169 += val.f169;
        f170 += val.f170;
        f171 += val.f171;
        f172 += val.f172;
        f173 += val.f173;
        f174 += val.f174;
        f175 += val.f175;
        f176 += val.f176;
        f177 += val.f177;
        f178 += val.f178;
        f179 += val.f179;
        f180 += val.f180;
        f181 += val.f181;
        f182 += val.f182;
        f183 += val.f183;
        f184 += val.f184;
        f185 += val.f185;
        f186 += val.f186;
        f187 += val.f187;
        f188 += val.f188;
        f189 += val.f189;
        f190 += val.f190;
        f191 += val.f191;
        f192 += val.f192;
        f193 += val.f193;
        f194 += val.f194;
        f195 += val.f195;
        f196 += val.f196;
        f197 += val.f197;
        f198 += val.f198;
        f199 += val.f199;
        f200 += val.f200;
        f201 += val.f201;
        f202 += val.f202;
        f203 += val.f203;
        f204 += val.f204;
        f205 += val.f205;
        f206 += val.f206;
        f207 += val.f207;
        f208 += val.f208;
        f209 += val.f209;
        f210 += val.f210;
        f211 += val.f211;
        f212 += val.f212;
        f213 += val.f213;
        f214 += val.f214;
        f215 += val.f215;
        f216 += val.f216;
        f217 += val.f217;
        f218 += val.f218;
        f219 += val.f219;
        f220 += val.f220;
        f221 += val.f221;
        f222 += val.f222;
        f223 += val.f223;
        f224 += val.f224;
        f225 += val.f225;
        f226 += val.f226;
        f227 += val.f227;
        f228 += val.f228;
        f229 += val.f229;
        f230 += val.f230;
        f231 += val.f231;
        f232 += val.f232;
        f233 += val.f233;
        f234 += val.f234;
        f235 += val.f235;
        f236 += val.f236;
        f237 += val.f237;
        f238 += val.f238;
        f239 += val.f239;
        f240 += val.f240;
        f241 += val.f241;
        f242 += val.f242;
        f243 += val.f243;
        f244 += val.f244;
        f245 += val.f245;
        f246 += val.f246;
        f247 += val.f247;
        f248 += val.f248;
        f249 += val.f249;
        f250 += val.f250;
        f251 += val.f251;
        f252 += val.f252;
        f253 += val.f253;
        f254 += val.f254;
        f255 += val.f255;
        f256 += val.f256;
        f257 += val.f257;
    }
};


// ---------------------------------
// VType8
// ---------------------------------
struct VType8 {
    void reset() {
    }
    void add(VType8 val) {
    }
};
