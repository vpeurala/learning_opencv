#include <opencv2/core/cvdef.h>
#include <opencv2/core/mat.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

const cv::Mat colorReduce(const cv::Mat& input, int div = 64) {
	cv::Mat output = input.clone();

	int nl = output.rows;
	int nc = output.cols * output.channels();

	for (int i = 0; i < nl; i++) {
		uchar* data = output.ptr<uchar>(i);

		for (int j = 0; j < nc; j++) {
			data[j] = data[j] / div * div + div / 2;
		}
	}

	return output;
}

int main(int argc, char** argv) {
	if (argc != 3) {
		std::cerr << "Incorrect number of command line arguments (2 expected): "
				<< (argc - 1) << "\n";
		return 1;
	}
	const char* inputFileName = argv[1];
	const char* outputFileName = argv[2];
	std::cout << "Opening image" << inputFileName << "\n";
	cv::Mat input = cv::imread(inputFileName);
	std::cout << "Image opened: " << inputFileName << "\n";
	cv::Mat output = colorReduce(input);
	std::cout << "Writing color reduced version to " << outputFileName << "\n";
	cv::imwrite(outputFileName, output);
	return 0;
}
