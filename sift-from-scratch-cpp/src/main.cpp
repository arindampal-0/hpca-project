#include <iostream>
#include <vector>

std::vector<std::vector<float>> convolution(std::vector<std::vector<float>> input, std::vector<std::vector<float>> kernel)
{
    std::vector<std::vector<float>> output(input.size());

    for(int i = 0; i < input.size(); ++i)
    {
        std::vector<float> input_row = input[0];
        for (int j = 0; j < input_row.size(); ++j)
        {
            output[i][j] = input_row[j] + kernel[i][j];
        }
    }

    return output;
}

int main(int argc, char* argv[])
{
    std::cout << "Convolution\n";
    return 0;
}