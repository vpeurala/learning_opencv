#include <opencv2/core/cvdef.h>
#include <opencv2/core/mat.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

void colorReduce(cv::Mat& image, int div = 64) {
	int nl = image.rows;
	int nc = image.cols * image.channels();

	for (int i = 0; i < nl; i++) {
		uchar* data = image.ptr<uchar>(i);

		for (int j = 0; j < nc; j++) {
			data[j] = data[j] / div * div + div / 2;
		}
	}
}

int main(int argc, char** argv) {
	if (argc != 3) {
		std::cerr << "Incorrect number of command line arguments (2 expected): "
				<< (argc - 1) << "\n";
		return 1;
	}
	std::cout << "Opening image" << argv[1] << "\n";
	cv::Mat image = cv::imread(argv[1]);
	std::cout << "Image opened, size: " << image.size << "\n";
	colorReduce(image);
	std::cout << "Writing color reduced version to " << argv[2] << "\n";
	cv::imwrite(argv[2], image);
	return 0;
}
