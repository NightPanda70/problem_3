long possiblePathsRecursive(int M, int N) {
    if (M==0 || N==0) {
        return 0;
    }

    if (M+N==2) {
        return 1;
    }

    return possiblePathsRecursive(M-1, N) + possiblePathsRecursive(M, N-1);
}

long possiblePathsIterative(int M, int N) {
	//make an array
	int* array = new int[M * N];//MAX Size N*M
	
	//fill first Row with 1
	for (int i = 0; i < N; i++) {
		array[0 * N + i] = 1;
	}//end for
	//fill in the colum with 1
	for (int i = 0; i < M; i++) {
		array[i * N + 0] = 1;
	}//end for

	//add up all the possable paths that can happen.
	//then once it's done return the last element of the array
	for (int i = 1; i < M; i++) {
		for (int j = 1; j < N; j++) {
			array[i * N + j] = array[(i - 1) * N + j] + array[i * N + j - 1];
		}//end inner for
	}//end for
	return array[(M - 1) * N + (N - 1)];
	delete[] array;
}
