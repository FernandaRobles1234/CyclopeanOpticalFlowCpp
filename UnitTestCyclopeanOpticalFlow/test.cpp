#include "pch.h"


#include "../CyclopeanOpticalFlow/tools.h"
#include "../CyclopeanOpticalFlow/pyramid.h"
#include "../CyclopeanOpticalFlow/displayResults.h"

//TODO: Do negative numbers Test
TEST(tools, uniformDistribution2DTest1) {
	int size = 10;

	
	float minNumber = 2.0;
	float maxNumber = 5.0;
	
	Matrix2D<float> listV0;
	listV0.reserve(size);
	
	listV0= uniformDistribution2D(size, minNumber, maxNumber, true);

	bool criteria = true;

	for (std::vector<float> v0 : listV0) {
		if (minNumber <= v0[0]+v0[1] && v0[0]+v0[1] <= maxNumber) {
		}
		else {
			criteria = false;
			break;
		}
	}

	EXPECT_TRUE(criteria);
}

TEST(tools, pearsonCorrelationTest1) {
	float r = 0.0;

	std::vector<float> x = { 1, 2, 3, 4, 5 };
	std::vector<float> y = { 2, 4, 6, 8, 10 };

	r = pearsonCorrelation(&x[0], &y[0], (int)x.size());

	EXPECT_TRUE(isEqual((float)1.0, r));
}

TEST(tools, pearsonCorrelationTest2) {
	float r = 0.0;

	std::vector<float> x = { 1, 2, 3, 4, 5 };
	std::vector<float> y = { 3, 5, 6, 7, 9 };

	r = pearsonCorrelation(&x[0], &y[0], (int)x.size());

	EXPECT_TRUE((float)0.0 < r);
}

TEST(tools, L2NormTest1) {
	std::vector<float> v = { 1, 2, 3, 4, 5 };
	float norm = 0;

	norm = L2Norm(v);


	EXPECT_TRUE(isEqual((float)7.416198487 , norm));
}

TEST(pyramid, padVectorTest1) {
	std::vector<float> v = { 1, 2, 3, 4, 5 };
	int padStart = 1;
	int padEnd = 1;
	int startSize = (int)v.size() + padStart + padEnd;

	padVector(v, padStart, padEnd);


	EXPECT_TRUE(isEqual((int)v.size(), startSize));
}

TEST(pyramid, generatePyramidFunctionsTest1) {
	std::vector<float> v = { 0., 0., 0., 0., 0., 0., 0., 0., 0., 0.0993805, 0.90062, 1., 1., 1., 
		1., 1., 1., 0.90062, 0.0993805, 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0. };

	//TODO: Check if they are at least 5 points for the interpolation
	std::vector<fun<float>> vf = generatePyramidFunctions(v, 1);


	display_function(vf[0], vf[1], 0, (int)v.size());


	EXPECT_TRUE(true);
}

