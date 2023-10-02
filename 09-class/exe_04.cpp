#include <stdio.h>

void merge_sort_words (char words_list[][20], int length) {
  char swap[20];

  if (length > 1) {
    int mid = length / 2;
    char left[mid][20];
    char right[length - mid][20];

    for (int i = 0; i < mid; i++) {
      for (int j = 0; j < 20; j++) {
        left[i][j] = words_list[i][j];
      }
    }

    for (int i = mid; i < length; i++) {
      for (int j = 0; j < 20; j++) {
        right[i - mid][j] = words_list[i][j];
      }
    }

    merge_sort_words(left, mid);
    merge_sort_words(right, length - mid);

    int i = 0, j = 0, k = 0;

    while (i < mid && j < length - mid) {
      if (left[i][0] < right[j][0]) {
        for (int l = 0; l < 20; l++) {
          words_list[k][l] = left[i][l];
        }
        i++;
      } else {
        for (int l = 0; l < 20; l++) {
          words_list[k][l] = right[j][l];
        }
        j++;
      }

      k++;
    }

    while (i < mid) {
      for (int l = 0; l < 20; l++) {
        words_list[k][l] = left[i][l];
      }
      i++;
      k++;
    }

    while (j < length - mid) {
      for (int l = 0; l < 20; l++) {
        words_list[k][l] = right[j][l];
      }
      j++;
      k++;
    }
  }
}

int main (void) {
  char words_list[20][20];

  for (int i = 0; i < 20; i++) {
    printf("Enter a word: ");
    scanf("%s", words_list[i]);
  }

  merge_sort_words(words_list, 20);

  for (int i = 0; i < 20; i++) {
    if (words_list[i][0] == 'a' || words_list[i][0] == 'e' || words_list[i][0] == 'i' || words_list[i][0] == 'o' || words_list[i][0] == 'u') {
      printf("%s\n", words_list[i]);
    }
  }

  return 0;
}
