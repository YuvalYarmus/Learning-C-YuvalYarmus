struct MaxHeap{
    int size = 0;
    void swap(int *a, int *b)
    {
        int temp = *b;
        *b = *a;
        *a = temp;
    }

    void heapify(int array[], int size, int i)
    {
        int largest = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        if (l < size && array[l] > array[largest])
            largest = l;
        if (r < size && array[r] > array[largest])
            largest = r;
        if (largest != i)
        {
            int temp = array[largest];
            array[largest] = array[i];
            array[i] = temp;
            heapify(array, size, largest);
        }
    }

    void heapSort(int arr[], int n)
    {
        // Build heap (rearrange array)
        for (int i = n / 2 - 1; i >= 0; i--)
            heapify(arr, n, i);

        // One by one extract an element from heap
        for (int i = n - 1; i > 0; i--)
        {
            // Move current root to end
            int temp = arr[i];
            arr[i] = arr[0];
            arr[0] = temp;

            // call max heapify on the reduced heap
            heapify(arr, i, 0);
        }
    }
};