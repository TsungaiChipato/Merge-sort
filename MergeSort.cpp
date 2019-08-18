#include <iostream>
#include <vector>

void MergeSort(std::vector<int>&block_1, std::vector<int>& block_2, std::vector<int>& elements) {
    int size_1 = block_1.size();
    int size_2 = block_2.size();
    int i = 0, j = 0, k = 0;

    // Sort by swapping elements in blocks.
    for (i = 0; j < size_1 && k < size_2; i++) {
      if (block_1[j] < block_2[k]) {
          elements[i] = block_1[j];
          j++;
      }
      else {
          elements[i] = block_2[k];
          k++;
      }
    }

    while (j < size_1) {
        elements[i] = block_1[j];
        j++; i++;
    }
    while (k < size_2) {
        elements[i] = block_2[k];
        k++; i++;
    }
}

void Sort(std::vector<int> &elements){

  int count = elements.size();
  int half = count / 2;

  if (elements.size() <= 1){
    return;
  }
  // Divides the vector into two halves.
  std::vector<int> block_1, block_2;

  for (int i = 0; i < half; i++){
    block_1.push_back(elements[i]);
  }
  for (int i = half; i < count; i++) {
    block_2.push_back(elements[i]);
  }

  // Performs mergesort algorithm.
  Sort(block_1);
  Sort(block_2);
  MergeSort(block_1, block_2, elements);
}

int main() {

  try{
    int count, input = 0;
    std::vector<int> elements;

    // Input for vector to be sorted.
    std::cout << "Enter number of elements: ";
    std::cin >> count;
    if (std::cin.fail()) {
      std::cout << "Exception caught non interger entered."<<std::endl;
      return 1;
    }
    std::cout << "Enter numbers to be sorted: ";
    for (int i = 0; i < count; i++) {
      std::cin >> input;
      if (std::cin.fail()) {
        std::cout << "Exception caught non interger entered."<<std::endl;
        return 1;
      }
      elements.push_back(input);
    }

    // Elements to be sorted.
    std::cout << "Numbers before sorting: ";
    for (int i = 0; i < count; i++) {
      std::cout << elements[i] << " ";
    }
    std::cout<< std::endl;

    // Sort vector elements.
    Sort(elements);

    // Sorted output.
    std::cout << "Numbers after sorting: ";
    for (int i = 0; i < count; i++) {
      std::cout << elements[i] << " ";
    }
    std::cout<< std::endl;
  }
  catch (const std::system_error& e) {
    std::cout << "Exception caught (system_error)"<< std::endl;
    std::cout << "Error: " << e.what() << '\n';
  }
  return 0;
}
