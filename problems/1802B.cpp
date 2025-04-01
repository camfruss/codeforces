#include <algorithm>
#include <cassert>
#include <fstream>
#include <iostream>
#include <limits>
#include <ranges>
#include <sstream>
#include <string>
#include <vector>


class solution 
{
	public:
		void operator()()
		{
			// std::ifstream ifs { "./tests/1802B.txt" };

			int num_tests;
			std::cin >> num_tests;
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			std::ostringstream oss;
			std::string line {};

			int count {};
			while (std::getline(std::cin, line)) 
			{
				if (++count % 2) continue;

				std::istringstream iss { line };
				
				std::vector<int> plan;
				std::ranges::copy(
					std::views::istream<int>(iss), 
					std::back_inserter(plan)
				);

				int answer = settlement_of_guinea_pigs(plan.size(), plan);
				oss << answer << '\n';
			}

			std::cout << oss.str();
		}

		int settlement_of_guinea_pigs(int days_planned, std::vector<int> plan)
		{
			int result {}, known {}, unknown {};

			for (auto decision : plan) {
				if (decision == 1) {
					++unknown;
				} else { // == 2
					known += unknown;
					unknown = 0;
				}
				auto known_cages = known > 0 ? static_cast<int>(known / 2) + 1 : 0;
				result = std::max(known_cages + unknown, result);
			}

			return result;
		}

} solution;

int main()
{
	solution();
};

