#include <iostream>
#include <opencv2/core/mat.hpp>
#include <vector>

#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/features2d.hpp>

int main(int argc, char* argv[])
{
    std::cout << "SIFT algorithm\n";

    cv::Mat img = cv::imread("home.jpg");
    std::cout << "image size: " << img.size << "\n";
    cv::Mat imgGray = img.clone();
    cv::cvtColor(img, imgGray, cv::COLOR_BGR2GRAY);

    cv::Ptr<cv::SIFT> detector = cv::SIFT::create();
    std::vector<cv::KeyPoint> keypoints;

    detector->detect(imgGray, keypoints);

    cv::KeyPoint keypoint = keypoints.at(0);
    std::cout << "keypoints[0]:\n";
    std::cout << "\t class_id: \t" << keypoint.class_id << "\n";
    std::cout << "\t angle: \t" << keypoint.angle << "\n";
    std::cout << "\t octave: \t" << keypoint.octave << "\n";
    std::cout << "\t pt: \t\t" << keypoint.pt << "\n";
    std::cout << "\t size: \t\t" << keypoint.size << "\n";
    std::cout << "\t response: \t" << keypoint.response << "\n";

    
    std::vector<std::vector<int>> descriptors;
    detector->compute(imgGray, keypoints, descriptors);

    std::cout << "descriptors[0]: \n";
    std::cout << "{ ";
    for (int val: descriptors[0])
    {
        std::cout << val << ", ";
    }
    std::cout << " }\n";

    cv::Mat annotatedImg = img.clone();
    cv::drawKeypoints(img, keypoints, annotatedImg, cv::Scalar::all(-1), cv::DrawMatchesFlags::DRAW_RICH_KEYPOINTS);

    cv::imwrite("sift_keypoints.jpg", annotatedImg);

    return 0;
}