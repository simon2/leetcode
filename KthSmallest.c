void heapify(int* data, int index, int size){
  int left = index * 2 + 1;
  int right = index * 2 + 2;
  int largest;
  if(left < size && data[left] > data[index]){
    largest = left;
  }else{
    largest = index;
  }
  if(right < size && data[right] > data[largest]){
    largest = right;
  }
  if(largest != index){
    int temp = data[index];
    data[index] = data[largest];
    data[largest] = temp;
    heapify(data, largest, size);
  }
}

void build_heap(int* data, int size){
  int i;
  for(i=(size-1)/2;i>=0;i--){
    heapify(data,i,size);
  }
}

int kthSmallest(int** matrix, int matrixSize, int* matrixColSize, int k){
    int i,j;
    int* heap = (int*)malloc(sizeof(int) * k);
    for(i=0;i<k;i++){
        int row = i / (*matrixColSize);
        int col = i % (*matrixColSize);
        heap[i] = matrix[row][col];
    }
    build_heap(heap, k);
    for(i=0;i<matrixSize;i++){
        for(j=0;j<(*matrixColSize);j++){
            if(i*(*matrixColSize)+j < k){
                continue;
            }
            if(matrix[i][j] <= heap[0]){
                heap[0] = matrix[i][j];
                heapify(heap,0,k);
            }else{
                break;
            }
        }
    }
    return heap[0];
}