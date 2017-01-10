#ifndef __FACEVERI_H__
#define __FACEVERI_H__

#define FEAT_DIM 256

struct FACERC
{
	int x, y, width, height;
};

void faceVeriInit(char* faceVeriConfigPath);
int faceFeatureExtractCamera(char* imgPath, FACERC& rc, float** featc, int isCompare);
int faceFeatureExtractIDCard(char* imgPath, FACERC& rc, float** feati);
int faceFeatureCompare(float* score);
void faceVeriFree();
#endif // __FACEVERI_H__