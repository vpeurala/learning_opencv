#include <opencv2/core/mat.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

int main(int argc, char** argv) {
	if (argc != 2) {
		std::cerr << "Incorrect number of command line arguments (1 expected): "
				<< (argc - 1) << "\n";
		return 1;
	}
	std::cout << "Opening image" << argv[1] << "\n";
	cv::Mat image = cv::imread(argv[1]);
	std::cout << "Image opened, size: " << image.size << "\n";
	return 0;
}
