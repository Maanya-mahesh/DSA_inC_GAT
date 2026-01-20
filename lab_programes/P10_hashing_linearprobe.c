#include <stdio.h>
#include <stdlib.h>
int tsize, hash[10], count = 0;

int cal_hash(int key) {
  return key % tsize;
}

int cal_rehash(int index) {
  return (index + 1) % tsize;
}

void insert(int key) {
  int index;
  if (count != tsize) {
    index = cal_hash(key);
    while (hash[index] != -1) {
      index = cal_rehash(index);
    }
    hash[index] = key;
    count++;
  } else {
    printf("Hash Table is full\n");
  }
}

int search(int key) {
  int i, index, loc = -1;
  index = cal_hash(key);
  for (i = 0; i < tsize; i++) {
    loc = (index + i) % tsize;
    if (hash[loc] == key) {
      return loc;
    }
  }
  return -1;
}

void delete(int key) {
  int loc;
  if (count == 0) {
    printf("Hash Table empty, can't delete\n");
  } else {
    loc = search(key);
    if (loc != -1) {
      hash[loc] = -1;
      count--;
      printf("Key deleted\n");
    } else {
      printf("Key not found\n");
    }
  }
}

void display() {
  int i;
  printf("The elements in hash Table are:\n");
  for (i = 0; i < tsize; i++) {
    printf("Element at %d: %d\n", i, hash[i]);
  }
}

int main() {
  int key, i, ch, loc;
  printf("Enter size of hash table: ");
  scanf("%d", &tsize);
  for (i = 0; i < tsize; i++) {
    hash[i] = -1;
  }
  while (1) {
    printf("1. Insert\n2. Search\n3. Delete\n4. Display\n5. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &ch);
    switch (ch) {
      case 1:
        printf("Enter key to insert: ");
        scanf("%d", &key);
        insert(key);
        break;
      case 2:
        printf("Enter key to search: ");
        scanf("%d", &key);
        loc = search(key);
        if (loc != -1)
          printf("Key found at %d\n", loc);
        else
          printf("Key not found\n");
        break;
      case 3:
        printf("Enter key to delete: ");
        scanf("%d", &key);
        delete(key);
        break;
      case 4:
        display();
        break;
      case 5:
        exit(0);
      default:
        printf("Invalid choice\n");
    }
  }
  return 0;
}
