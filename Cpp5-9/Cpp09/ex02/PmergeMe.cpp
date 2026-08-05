#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){

}

PmergeMe::PmergeMe(const PmergeMe &obj){
    *this = obj;
}

PmergeMe::~PmergeMe(){

}

PmergeMe &PmergeMe::operator=(const PmergeMe &obj){
    if (this != &obj){
        this->vec = vec;
        this->deq = deq;
    }
        return *this;
}

static double calculateTime(struct timeval start, struct timeval end) {
    return (end.tv_sec - start.tv_sec) * 1000000.0 + (end.tv_usec - start.tv_usec);
}

void PmergeMe::process(int ac, char **av) {

    if (!parseArguments(ac, av)) // parse arg and store them
        return ;
    std::cout << "Before: ";
    for (size_t i = 0; i < vec.size(); i++)
        std::cout << vec[i] << " ";
    std::cout << "\n";

    // benchmark vector
    struct timeval start_vec, end_vec;
    gettimeofday(&start_vec, NULL);
    fordJohnsonVector(vec);
    gettimeofday(&end_vec, NULL);

    double time_vec = calculateTime(start_vec, end_vec);

    //benchmark deque
    struct timeval start_deq, end_deq;
    gettimeofday(&start_deq, NULL);
    fordJohnsonDeque(deq);
    gettimeofday(&end_deq, NULL);

    double time_deq = calculateTime(start_vec, end_vec);

    std::cout << "After: ";
    for (size_t i = 0; i < vec.size(); i++)
        std::cout << vec[i] << " ";
    std::cout << "\n";

    std::cout << "Time to process a range of " << vec.size()
              << " element with std::vector : " << time_vec << " us\n";
    
    std::cout << "Time to process a range of " << deq.size()
              << " element with std::deque : " << time_deq << " us\n";
}

bool PmergeMe::parseArguments(int ac, char **av) {
    if (ac < 2){
        std::cout << "Error\n";
        return false;       
    }

    for (int i = 1;i < ac; i++){
        std::string arg = av[i];
        if (arg.empty()){
            std::cout << "Error\n";
            return false;
        }
        size_t j = 0;

        if (arg[0] == '+'){
            j++;
            if (arg.length() == 1){
                std::cout << "Error\n";
                return false;                
            }
        }

        for (; j < arg.length(); j++){
            if (!isdigit(arg[j])){
                std::cout << "Error\n";
                return false;                
            }
        }

        long val = std::atol(arg.c_str());

        if (val < 0 || val > __INT_MAX__){
            std::cout << "Error\n";
            return false;
        }
        vec.push_back(static_cast<int>(val));
        deq.push_back(static_cast<int>(val));
    }
    return true;
}

void PmergeMe::fordJohnsonVector(std::vector<int>& arr){
    if (arr.size() < 2)
        return ;
    
    int straggler_value = 0;
    bool has_straggler = false;

    if (arr.size() % 2 != 0){
        straggler_value = arr.back();
        has_straggler = true;
        arr.pop_back();
    }

    std::vector<std::pair<int, int> > pairs;
    for (size_t i = 0; i < arr.size(); i+=2){
        int winner = arr[i];
        int loser = arr[i + 1];
        if (winner < loser)
            std::swap(winner, loser);
        pairs.push_back(std::make_pair(winner, loser));
    }

    std::vector<int> winners;
    for (size_t i = 0;i < pairs.size(); i++)
        winners.push_back(pairs[i].first);
    fordJohnsonVector(winners);

    std::vector<int> mainChain;
    std::vector<int> pend;
    std::vector<bool> used(pairs.size(), false);

    for (size_t i = 0; i < winners.size(); i++){
        for (size_t j = 0; j < pairs.size(); j++){
            if (!used[j] && pairs[j].first == winners[i]){
                used[j] = true;
                mainChain.push_back(winners[i]);
                pend.push_back(pairs[j].second);
                break ;
            }
        }
    }
    if (has_straggler)
        pend.push_back(straggler_value);

    mainChain.insert(mainChain.begin(), pend[0]);
    std::vector<int> jacob = generateJacobsthal(pend.size());

    int lastPos = 1;

    for (size_t i = 1;i < jacob.size();i++){
        int currPos = jacob[i];
        for (int j = currPos;j > lastPos; j--){
            int elementToInsert = pend[j - 1];

            std::vector<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), elementToInsert);
            mainChain.insert(it, elementToInsert);
        }
        lastPos = currPos;
    };
    arr = mainChain;
}

std::vector<int> PmergeMe::generateJacobsthal(size_t size){
    std::vector<int> jacob;

    if (size == 0)
        return jacob;
    
    jacob.push_back(1);
    if (size == 1)
        return jacob;
    
    int j1 = 1;
    int j2 = 1;

    while (true){
        int next = j1 + 2 * j2;

        if (static_cast<size_t>(next) >= size){
            jacob.push_back(static_cast<int>(size));
            break;
        }

        jacob.push_back(next);

        j2 = j1;
        j1 = next;
    }
    return jacob;
}

void PmergeMe::fordJohnsonDeque(std::deque<int>& arr){
    if (arr.size() < 2)
        return ;
    int straggler_value = 0;
    bool has_straggler = false;
    if (arr.size() % 2 != 0){
        straggler_value = arr.back();
        has_straggler = true;
        arr.pop_back();
    }

    std::deque<std::pair<int, int> > pairs;
    for (size_t i = 0; i < arr.size(); i += 2){
        int winner = arr[i];
        int loser = arr[i + 1];
        if (winner < loser)
            std::swap(winner, loser);
        pairs.push_back(std::make_pair(winner, loser));
    }

    std::deque<int> winners;
    for (size_t i = 0; i < pairs.size(); i++){
        winners.push_back(pairs[i].first);
    }
    std::deque<int> mainChain;
    std::deque<int> pend;
    std::deque<bool> used(pairs.size(), false);

    for (size_t i = 0; i < winners.size(); i++){
        for (size_t j = 0; j < pairs.size(); j++){
            if (!used[j] && pairs[j].first == winners[i]){
                used[j] = true;
                mainChain.push_back(winners[i]);
                pend.push_back(pairs[j].second);
                break ;
            }
        }
    }
    if (has_straggler)
        pend.push_back(straggler_value);

    mainChain.insert(mainChain.begin(), pend[0]);
    std::vector<int> jacob = generateJacobsthal(pend.size());

    int lastPos = 1;

    for (size_t i = 1;i < jacob.size();i++){
        int currPos = jacob[i];
        for (int j = currPos;j > lastPos; j--){
            int elementToInsert = pend[j - 1];

            std::deque<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), elementToInsert);
            mainChain.insert(it, elementToInsert);
        }
        lastPos = currPos;
    };
    arr = mainChain;
}