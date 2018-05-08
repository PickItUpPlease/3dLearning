

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