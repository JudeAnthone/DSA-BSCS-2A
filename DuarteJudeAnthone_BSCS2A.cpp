#include <iostream>
using namespace std;

void mergeFunction(int array[], int start, int mid, int end);
void devideSort(int array[], int start, int end);
void print(int array[], int inputSize);

int main()
{
  int inputSize;
  cout << "Enter Array Size: ";
  cin >> inputSize;

  int array[inputSize];

  cout << "Enter Array Elements that you want to be sorted: \n";
  for (int i = 0; i < inputSize; i++)
  {
    cout << "Number " << i + 1 << ": ";
    cin >> array[i];
  }

  // printing of the user inputs
  cout << "Your Elements: ";
  print(array, inputSize);

  devideSort(array, 0, inputSize - 1);

  cout << "Sorted Input: ";
  print(array, inputSize);

  return 0;
}

void mergeFunction(int array[], int start, int mid, int end)
{
  int leftTemp = mid - start + 1; // temporary storage of unsorted inputs
  int rightTemp = end - mid;

  int leftSubArray[leftTemp]; // holder of temporary inputts
  int rightSubArray[rightTemp];

  for (int i = 0; i < leftTemp; i++)
    leftSubArray[i] = array[start + i];

  for (int j = 0; j < rightTemp; j++)
    rightSubArray[j] = array[mid + 1 + j];

  int i = 0, j = 0, k = start;

  // merging of arrays together
  while (i < leftTemp && j < rightTemp)
  {
    if (leftSubArray[i] <= rightSubArray[j])
    {
      array[k] = leftSubArray[i];
      i++;
    }
    else
    {
      array[k] = rightSubArray[j];
      j++;
    }
    k++;
  }

  while (i < leftTemp)
  {
    array[k] = leftSubArray[i];
    i++;
    k++;
  }

  while (j < rightTemp)
  {
    array[k] = rightSubArray[j];
    j++;
    k++;
  }
}

// devider
void devideSort(int array[], int start, int end)
{
  if (start < end)
  {
    int mid = start + (end - start) / 2;

    devideSort(array, start, mid);   // sorting the lefts
    devideSort(array, mid + 1, end); // sorting the rights
    mergeFunction(array, start, mid, end);
  }
}

void print(int array[], int inputSize)
{
  for (int i = 0; i < inputSize; i++)
    cout << array[i] << " ";
  cout << endl;
}
