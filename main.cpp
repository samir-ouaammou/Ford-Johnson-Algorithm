#include <iostream>
#include <algorithm>
#include <sys/time.h>
#include <vector>
#include <cstdlib>
#include <climits>
#include <iomanip>

/**
 * @brief Generate the insertion order for the "small" elements
 *        based on the Jacobsthal sequence logic.
 *
 * @param n The number of elements to generate order for.
 * @return A vector containing indices in the insertion order.
 */
std::vector<int> insertOrder(int n)
{
    std::vector<int> jacob;
    jacob.push_back(0);
    jacob.push_back(1);

    int prev = 1;
    int next = 3;
    while (static_cast<int>(jacob.size()) < n)
    {
        for (int i = (next >= n ? n - 1 : next); i > prev; --i)
        {
            jacob.push_back(i);
            if (static_cast<int>(jacob.size()) == n)
                break;
        }
        prev = next;
        next = next + 2 * prev;
    }
    return (jacob);
}


/**
 * @brief Sort a vector using the Merge-Insertion sort algorithm (Ford-Johnson).
 *        Elements are divided into pairs, sorted recursively, and inserted
 *        using a special insertion order (based on Jacobsthal).
 *
 * @param input The vector to be sorted (in-place).
 */
void sortVector(std::vector<int> &input)
{
    if (input.size() <= 1)
        return;

    std::vector<int> bigs;
    std::vector<int> smalls;

    // Step 1: Pairing elements into bigs and smalls
    for (size_t i = 0; i < input.size() - 1; i += 2)
    {
        if (input[i] > input[i + 1])
        {
            bigs.push_back(input[i]);
            smalls.push_back(input[i + 1]);
        }
        else
        {
            bigs.push_back(input[i + 1]);
            smalls.push_back(input[i]);
        }
    }

    // Handle leftover element if the input size is odd
    int leftover = (input.size() % 2 != 0) ? input.back() : -1;

    // Step 2: Recursively sort the bigs
    sortVector(bigs);

    // Step 3: Insert the smalls into the sorted bigs using a specific insertion order
    std::vector<int> sorted = bigs;

    if (!smalls.empty())
    {
        std::vector<int> indeces = insertOrder(smalls.size());
        for (size_t i = 0; i < smalls.size(); ++i)
        {
            int idx = indeces[i];
            std::vector<int>::iterator pos = std::lower_bound(sorted.begin(), sorted.end(), smalls[idx]);
            sorted.insert(pos, smalls[idx]);
        }
    }

    // Step 4: Insert the leftover element if exists
    if (leftover != -1)
    {
        std::vector<int>::iterator pos = std::lower_bound(sorted.begin(), sorted.end(), leftover);
        sorted.insert(pos, leftover);
    }

    // Update the input with the sorted result
    input = sorted;
}


/**
 * @brief Print a vector with a given label.
 *
 * @param vector The vector to print.
 * @param str A label to display before the values.
 */
void printContainer(const std::vector<int> &vector, std::string str)
{
    std::cout << str << ": ";
    for (size_t i = 0; i < vector.size(); i++)
        std::cout << vector[i] << " ";
    std::cout << std::endl;
}


/**
 * @brief Get the current time in microseconds.
 *
 * @return The current timestamp in microseconds.
 */
long long getTimeMicroseconds()
{
    struct timeval time;
    gettimeofday(&time, NULL);
    return (long long)(time.tv_sec) * 1000000 + time.tv_usec;
}


/**
 * @brief Print the elapsed time of the sorting operation.
 *
 * @param start The starting time (in microseconds).
 * @param end The ending time (in microseconds).
 * @param size The size of the sorted vector.
 */
void printTiming(long long start, long long end, size_t size)
{
    std::cout << std::fixed << std::setprecision(5);
    std::cout << "Time to process a range of " << size
              << "  elements with std::vector : "
              << static_cast<double>(end - start) << " us" << std::endl;
}


/**
 * @brief Parse input arguments from command line, validate and store as integers.
 *
 * @param ac Argument count.
 * @param av Argument vector.
 * @return A vector of parsed and validated integers.
 *
 * @throws std::runtime_error if any input is invalid or duplicated.
 */
std::vector<int> parseInput(int &ac, char **av)
{
    std::vector<int> result;
    for (int i = 1; i < ac; ++i)
    {
        char *end;
        long num = std::strtol(av[i], &end, 10);
        if (*end != '\0' || num < 0 || num > INT_MAX)
            throw std::runtime_error("Error: Invalid input -> " + static_cast<std::string>(av[i]));

        bool isDuplicate = (std::find(result.begin(), result.end(), num) != result.end());
        if (isDuplicate)
            throw std::runtime_error("Error: Duplicate number found: " + static_cast<std::string>(av[i]));

        result.push_back(static_cast<int>(num));
    }
    return (result);
}


/**
 * @brief Entry point of the program.
 *
 * @param ac Argument count.
 * @param av Argument vector.
 * @return int Exit status.
 */
int main(int ac, char **av)
{
    if (ac < 2)
    {
        std::cerr << "Usage: ./PmergeMe <numbers...>" << std::endl;
        return (1);
    }

    try
    {
        std::vector<int> input;
        long long timeStart;
        long long timeEnd;

        input = parseInput(ac, av);
        printContainer(input, "Before");
        timeStart = getTimeMicroseconds();
        sortVector(input);
        timeEnd = getTimeMicroseconds();
        printContainer(input, "After ");
        printTiming(timeStart, timeEnd, input.size());
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    return (0);
}
