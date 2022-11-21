#include <iostream>  // C++ 헤더 파일
#include <math.h>   //pow(), sqrt()함수 헤더 파일


using namespace std;
//여러 내장 루틴을 선언하는 std로 알려진 네임스페이스

float main(int argc, char** argv) {
    //char* 에 문자열을 저장가능

    //2차원 좌표+동차좌표
    float vec3[3][1] = { {4},{2},{1} };

    //2차원행렬

    //이동변환행렬 
    float Translate[3][3] = { {1,0,0},
                              {0,1,0},
                              {3,5,1} };
    //회전변환행렬
    float Rotate[3][3] = { {sqrt(3) / 2,1 / 2,0},
                           {1 / 2,sqrt(3) / 2,0},
                           {0,0,0} };
    //크기변환행렬
    float Scale[3][3] = { {2,0,0},
                          {0,2,0},
                          {0,0,1} };
    //결과값
    float Mat3[3][3] = { 0 };

    //(3X3행렬곱)X백터vec3 
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                for (int l = 0; l < 3; l++) {
                    for (int m = 0; m < 1; m++) {
                        Mat3[i][l] += Translate[i][k] * Rotate[k][j] * Scale[j][l] * vec3[l][m];
                    }
                }
            }
        }
    }

    //결과값 출력
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << Mat3[i][j];
            if (j < 2) cout << " ";
        }
        cout << endl;
    }
    return 0;
}