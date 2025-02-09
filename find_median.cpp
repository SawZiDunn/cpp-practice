#include <iostream>
#include <vector>
#include <algorithm> // For std::sort
#include <stdexcept> // For std::domain_error

// Function to compute the median of a vector<double>
double median(std::vector<double> vec)
{
    if (vec.empty())
        throw std::domain_error("median of an empty vector");

    // sorting a vector
    std::sort(vec.begin(), vec.end());

    // we can also use auto mid;
    std::vector<double>::size_type mid = vec.size() / 2;

    return vec.size() % 2 == 0 ? (vec[mid] + vec[mid - 1]) / 2 : vec[mid];
}

int main()
{
    try
    {
        std::vector<double> vec{1.5, 3.2, 6.0, 9.1, 4.6, 2.8};
        // std::cout << "The median is " << median(vec) << std::endl;
        std::cout << vec.begin() << vec.end() << std::endl;
    }
    catch (std::domain_error &e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
