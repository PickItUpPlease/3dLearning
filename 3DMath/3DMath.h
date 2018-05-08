

/*  常量
 *
 *
 */

#define PI      ((float)3.141592654f)
#define PI2     ((float)6.283185407f)
#define PI_DIV_2    ((float)1.570796327f)
#define PI_DIV_4    ((float)0.785398163f)
#define PI_INV      ((float)0.318309886f)

#define FIXP16_SHIFT    16
#define FIXP16_MAG      65536
#define FIXP16_DP_MASK  0x0000ffff
#define FIXP16_WP_MASK  0xffff0000
#define FIXP16_ROUND_UP 0x00008000

#define EPSILON_E4  (float)(1E-4)
#define EPSILON_E5  (float)(1E-5)
#define EPSILON_E6  (float)(1E-6)

#define PARM_LINE_NO_INTERSECT 0
#define PARM_LINE_INTERSECT_IN_SEGMENT 1
#define PARM_LINE_INTERSECT_OUT_SEGMENT 2
#define PARM_LINE_INTERSECT_EVERYWHERE 3

#define MIN(a, b) (((a) < (b))) ? (a) : (b)
#define MAX(a, b) (((a) > (b))) ? (a) : (b)

#define SWAP(a, b, t) {t = a; a = b; b = t;}

#define DEG_TO_RAD(ang) ((ang)*PI/180.0)
#define RAD_TO_DEG(rads) ((rads)*180.0/PI)

#define RAND_RANGE(x, y) ((x) + (rand() %((y) - (x) + 1)))


/*  VECTOR and POINT
 *
 *
 */

// 不包含 w 分量的2d 向量和点
typedef struct VECTOR2D_TYP
{
    union
    {
        float M[2]; //数组存储
        // 独立变量存储方式
        struct 
        {
            float x, y;
        }; // end struct
    }; // end union
	
}VECTOR2D, POINT2D, *VECTOR2D_PTR, *POINT2D_PTR;

// 不包含 w 分量的3d 向量和 点
typedef struct VECTOR3D_TYP
{
    union
    {
        float M[3];
        struct 
        {
            float x, y, z;
        };
    } 
}VECTOR3D, POINT3D, *VECTOR3D_PTR, *POINT3D_PTR;

// 包含 w 分量的 4D 齐次向量和点
typedef struct VECTOR4D_TYP
{
    union
    {
        float M[4];
        struct 
        {
            float x, y, z, w;
        };
    }
}VECTOR4D, POINT4D, *VECTOR4D_PTR, *POINT4D_PTR;

// 2d 整形 顶点
typedef struct VERTEX2DI_TYPE
{
    int x, y;
} VERTEX2DI, *VERTEX2DI_PTR;

typedef struct VERTEX2DF_TYPE
{
    float x, y;
} VERTEX2DF, *VERTEX2DF_PTR;


/*  LINE
 *
 *
 */
typedef struct PARMLINE2D_TYP
{
    POINT2D p0; //参数化直线的起点
    POINT2D P1; // 直线的终点
    VECTOR2D v; // 线段的方向
} PARMLINE2D, *PARMLINE2D_PTR;

typedef struct PARMLINE3D_TYP
{
    POINT3D p0; //参数化直线的起点
    POINT3D P1; // 直线的终点
    VECTOR3D v; // 线段的方向
} PARMLINE3D, *PARMLINE3D_PTR;


/*  PLAN
 *
 *
 */

typedef struct PLAN3D_TYP
{
    POINT3D p0; //平面上的点
    VECTOR3D n; //平面的法线
} PLAN3D, *PLAN3D_PTR;


/*  MATRIX
 *
 *
 */
//索引关系 [0..n][0..n]表示 [行索引][列索引]
// 4X4 矩阵
typedef struct MATRIX4X4_TYP
{
    union
    {
        float M[4][4];
        struct 
        {
            float M00, M01, M02, M03;
            float M10, M11, M12, M13;
            float M20, M21, M22, M23;
            float M30, M31, M32, M33;
        };
    };
}MATRIX4X4, *MATRIX4X4_PTR;

// 4X3 矩阵
typedef struct MATRIX4X3_TYP
{
    union
    {
        float  M[4][3];
        struct 
        {
            float M00, M01, M02;
            float M10, M11, M12;
            float M20, M21, M22;
            float M30, M31, M32;
        };
    }
} MATRIX4X3, *MATRIX4X3_PTR;

// 1X4 矩阵
typedef struct MATRIX1X4_TYP
{
    union
    {
        float M[4];
        struct
        {
            float M00, M01, M02, M03;
        }
    }
} MATRIX1X4, *MATRIX1X4_PTR;

// 3X3 矩阵
typedef struct MATRIX3X3_TYP
{
    union 
    {
        float M[3][3];
        struct 
        {
            float M00, M01, M02;
            float M10, M11, M12;
            float M20, M21, M22;
        };
    }
} MATRIX3X3, *MATRIX3X3_PTR;

// 1X3 矩阵
typedef struct MATRIX1X3_TYP
{
    union
    {
        float M[3];
        struct
        {
            float M00, M01, M02;
        }
    }
} MATRIX1X3, *MATRIX1X3_PTR;

// 3X2 矩阵
typedef struct MATRIX3X2_TYP
{
    union 
    {
        float M[3][2];
        struct 
        {
            float M00, M01;
            float M10, M11;
            float M20, M21;
        };
    }
} MATRIX3X2, *MATRIX3X2_PTR;

// 2X2 矩阵
typedef struct MATRIX2X2_TYP
{
    union 
    {
        float M[2][2];
        struct 
        {
            float M00, M01;
            float M10, M11;
        };
    }
} MATRIX2X2, *MATRIX2X2_PTR;

// 1X2 矩阵
typedef struct MATRIX1X2_TYP
{
    union 
    {
        float [2];
        struct 
        {
            float M00, M01;
        };
    }
} MATRIX1X2, *MATRIX1X2_PTR;

/*
 *  四元数
 *
 */

typedef struct QUAT_TYP
{
    union
    {
        float M[4];
        struct
        {
            float q0;
            VECTOR3D qv;
        };
        struct 
        {
            float w, x, y, z;
        };
    };
}QUAT, *QUAT_PTR;


/*
 *  极坐标
 *
 */

typedef struct POLAR2D_TYP
{
    float r;
    float theta;
} POLAR2D, * POLAR2D_PTR;


/*
 *  3D柱面坐标
 *
 */

typedef struct CYLINDRICAL3D_TYP
{
    float r;
    float theta;
    float z;
} CYLINDRICAL3D, * CYLINDRICAL3D_PTR;


/*
 *  3D球面坐标
 *
 */

typedef struct SPHERICAL3D_TYP
{
    float p;  //点到原点的距离
    float theta; // 线段 o->p 和正 z 轴之间的夹角
    float phi; //  线段 o->p 在x-y平面上的投影与 正 x 轴之间的夹角
} SPHERICAL3D, * SPHERICAL3D_PTR;


/*
 *  定点数
 *
 */

typedef int FIXP16;
typedef int *FIXP16_PTR;


// Identity Matrix
const MATRIX4X4 IMAT_4X4 = 
{
    1, 0, 0, 0,
    0, 1, 0, 0,
    0, 0, 1, 0,
    0, 0, 0, 1
};

// Identity Matrix
const MATRIX4X3 IMAT_4X3 = 
{
    1, 0, 0,
    0, 1, 0,
    0, 0, 1,
    0, 0, 0
};

// Identity Matrix
const MATRIX3X3 IMAT_3X3 = 
{
    1, 0, 0,
    0, 1, 0,
    0, 0, 1
};

// Identity Matrix
const MATRIX2X2 IMAT_2X2 = 
{
    1, 0,
    0, 1
};


//内联函数

inline void VECTOR2D_ZERO(VECTOR2D_PTR v)
{(v)->x = (v)->y = 0.0;}

inline void VECTOR3D_ZERO(VECTOR3D_PTR v)
{(v)->x = (v)->y = (v)->z = 0.0;}

inline void VECTOR4D_ZERO(VECTOR4D_PTR v)
{(v)->x = (v)->y = (v)->z = 0.0; (v)->w = 1.0;}

inline void VECTOR2D_INITXY(VECTOR2D_PTR v, float x, float y)
{(v)->x = (x); (v)->y = (y);}

inline void VECTOR3D_INITXYZ(VECTOR3D_PTR v, float x, float y, float z)
{(v)->x = (x); (v)->y = (y); (v)->z = (z);}

inline void VECTOR4D_INITXYZ(VECTOR4D_PTR v, float x, float y, float z)
{(v)->x = (x); (v)->y = (y); (v)->z = (z); (v)->w = 1.0;}

inline void VECTOR2D_INIT(VECTOR2D_PTR vdst, VECTOR2D_PTR vsrc)
{(vdst)->x = (vsrc)->x; (vdst)->y = (vsrc)->y;}

inline void VECTOR3D_INIT(VECTOR3D_PTR vdst, VECTOR3D_PTR vsrc)
{(vdst)->x = (vsrc)->x; (vdst)->y = (vsrc)->y; (vdst)->z = (vsrc)->z;}

inline void VECTOR4D_INIT(VECTOR4D_PTR vdst, VECTOR4D_PTR vsrc)
{(vdst)->x = (vsrc)->x; (vdst)->y = (vsrc)->y;
 (vdst)->z = (vsrc)->z; (vdst)->w = (vsrc)->w;}

inline void VECTOR2D_COPY(VECTOR2D_PTR vdst, VECTOR2D_PTR vsrc)
{(vdst)->x = (vsrc)->x; (vdst)->y = (vsrc)->y;}

inline void VECTOR3D_COPY(VECTOR3D_PTR vdst, VECTOR3D_PTR vsrc)
{(vdst)->x = (vsrc)->x; (vdst)->y = (vsrc)->y; (vdst)->z = (vsrc)->z;}

inline void VECTOR4D_COPY(VECTOR4D_PTR vdst, VECTOR4D_PTR vsrc)
{(vdst)->x = (vsrc)->x; (vdst)->y = (vsrc)->y;
 (vdst)->z = (vsrc)->z; (vdst)->w = (vsrc)->w;}

inline void POINT2D_INIT(POINT2D_PTR vdst, POINT2D_PTR vsrc)
{(vdst)->x = (vsrc)->x; (vdst)->y = (vsrc)->y;}

inline void POINT3D_INIT(POINT3D_PTR vdst, POINT3D_PTR vsrc)
{(vdst)->x = (vsrc)->x; (vdst)->y = (vsrc)->y; (vdst)->z = (vsrc)->z;}

inline void POINT4D_INIT(POINT4D_PTR vdst, POINT4D_PTR vsrc)
{(vdst)->x = (vsrc)->x; (vdst)->y = (vsrc)->y;
 (vdst)->z = (vsrc)->z; (vdst)->w = (vsrc)->w;}

inline void POINT2D_COPY(POINT2D_PTR vdst, POINT2D_PTR vsrc)
{(vdst)->x = (vsrc)->x; (vdst)->y = (vsrc)->y;}

inline void POINT3D_COPY(POINT3D_PTR vdst, POINT3D_PTR vsrc)
{(vdst)->x = (vsrc)->x; (vdst)->y = (vsrc)->y; (vdst)->z = (vsrc)->z;}

inline void POINT4D_COPY(POINT4D_PTR vdst, POINT4D_PTR vsrc)
{
    (vdst)->x = (vsrc)->x; (vdst)->y = (vsrc)->y;
    (vdst)->z = (vsrc)->z; (vdst)->w = (vsrc)->w;
}


#define MAT_ZERO_2X2(m) {memset((void*)(m), 0, sizeof(MATRIX2X2));}
#define MAT_ZERO_3X3(m) {memset((void*)(m), 0, sizeof(MATRIX3X3));}
#define MAT_ZERO_4X4(m) {memset((void*)(m), 0, sizeof(MATRIX4X4));}
#define MAT_ZERO_4X3(m) {memset((void*)(m), 0, sizeof(MATRIX4X3));}

#define MAT_IDENTITY_2X2(m) {memcpy((void*)(m), /
    (void*)&IMAT_2X2, sizeof(MATRIX2X2));}

#define MAT_IDENTITY_3X3(m) {memcpy((void*)(m), /
    (void*)&IMAT_3X3, sizeof(MATRIX3X3));}

#define MAT_IDENTITY_4X4(m) {memcpy((void*)(m), /
    (void*)&IMAT_4X4, sizeof(MATRIX4X4));}

#define MAT_IDENTITY_4X3(m) {memcpy((void*)(m), /
    (void*)&IMAT_4X3, sizeof(MATRIX4X3));}

#define MAT_COPY_2x2(src_mat, dst_mat) {memcpy((void*)(dst_mat), /
    (void*)(src_mat), sizeof(MATRIX2X2));}

#define MAT_COPY_3x3(src_mat, dst_mat) {memcpy((void*)(dst_mat), /
    (void*)(src_mat), sizeof(MATRIX3X3));}

#define MAT_COPY_4x4(src_mat, dst_mat) {memcpy((void*)(dst_mat), /
    (void*)(src_mat), sizeof(MATRIX4X4));}

#define MAT_COPY_4x3(src_mat, dst_mat) {memcpy((void*)(dst_mat), /
    (void*)(src_mat), sizeof(MATRIX4X3));}

//矩阵转置 宏
inline void MAT_TRANSPOSE_3X3(MATRIX3X3_PTR m)
{
    MATRIX3X3 mt;
    mt.M00 = m->M00; mt.M01 = m->M10; mt.M02 = m->M20;
    mt.M10 = m->M01; mt.M11 = m->M11; mt.M12 = m->M21;
    mt.M20 = m->M02; mt.M21 = m->M12; mt.M22 = m->M22;
    memcpy((void*)m, (void*)&mt, sizeof(MATRIX3X3));
}

inline void MAT_TRANSPOSE_4X4(MATRIX4X4_PTR m)
{
    MATRIX3X3 mt;
    mt.M00 = m->M00; mt.M01 = m->M10; mt.M02 = m->M20; mt.M03 = m->M30;
    mt.M10 = m->M01; mt.M11 = m->M11; mt.M12 = m->M21; mt.M13 = m->M31;
    mt.M20 = m->M02; mt.M21 = m->M12; mt.M22 = m->M22; mt.M23 = m->M32;
    mt.M30 = m->M03; mt.M31 = m->M13; mt.M32 = m->M23; mt.M33 = m->M33;
    memcpy((void*)m, (void*)&mt, sizeof(MATRIX3X3));
}

inline void MAT_TRANSPOSE_3X3(MATRIX3X3_PTR m, MATRIX3X3_PTR mt)
{
    mt->M00 = m->M00; mt->M01 = m->M10; mt->M02 = m->M20;
    mt->M10 = m->M01; mt->M11 = m->M11; mt->M12 = m->M21;
    mt->M20 = m->M02; mt->M21 = m->M12; mt->M22 = m->M22;
    memcpy((void*)m, (void*)mt, sizeof(MATRIX3X3));
}

inline void MAT_TRANSPOSE_4X4(MATRIX4X4_PTR m, MATRIX4X4_PTR mt)
{
    mt->M00 = m->M00; mt->M01 = m->M10; mt->M02 = m->M20; mt->M03 = m->M30;
    mt->M10 = m->M01; mt->M11 = m->M11; mt->M12 = m->M21; mt->M13 = m->M31;
    mt->M20 = m->M02; mt->M21 = m->M12; mt->M22 = m->M22; mt->M23 = m->M32;
    mt->M30 = m->M03; mt->M31 = m->M13; mt->M32 = m->M23; mt->M33 = m->M33;
    memcpy((void*)m, (void*)mt, sizeof(MATRIX4X4));
}


// 矩阵和向量互换
inline void MAT_COLUM_SWAP_2X2(MATRIX2X2_PTR m, int c, MATRIX1X2_PTR v)
{ m->M[0][c]=v->M[0]; m->M[1][c]=v->M[1];}

inline void MAT_COLUM_SWAP_3X3(MATRIX3X3_PTR m, int c, MATRIX1X3_PTR v)
{ m->M[0][c]=v->M[0]; m->M[1][c]=v->M[1]; m->M[2][c]=v->M[2];}

inline void MAT_COLUM_SWAP_4X4(MATRIX4X4_PTR m, int c, MATRIX1X4_PTR v)
{ m->M[0][c]=v->M[0]; m->M[1][c]=v->M[1]; m->M[2][c]=v->M[2]; m->M[3][c]=v->M[3];}

inline void MAT_COLUM_SWAP_4X3(MATRIX4X3_PTR m, int c, MATRIX1X4_PTR v)
{ m->M[0][c]=v->M[0]; m->M[1][c]=v->M[1]; m->M[2][c]=v->M[2]; m->M[3][c]=v->M[3];}