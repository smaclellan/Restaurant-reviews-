#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void printResults(struct *);
Restaurant *RestaurantFind(searchList[], keyword[], int numEntries);

typedef struct restaurant{
  char name[50];
  char type[50];
  double* averagePrice[50];
  double* rating[50];
  struct node *left;
  struct node *right;
}Restaurant;

int search_index=0;

main() {

  FILE *file;
  int reviewCount, totalReviews;
  int count;
  int numRes;
  //char buff[30];
  char line[30];// = NULL;
  size_t len = 0;
  ssize_t read;

  Restaurant *root = NULL;

  Restaurant *index;
  char entry[10]={0};
  int numEntries;

  file = fopen("test.txt", "r");




  fgets(line, sizeof(line), file);

  totalReviews = atoi(line);

  index = malloc(sizeof(Restaurant) * totalReviews);

  for(reviewCount = 0; reviewCount < totalReviews; reviewCount++){
    for(count = 0; count < 4 ; count++){
      fgets(line,sizeof(line),file);
      printf("Found %s", line);
      switch(count){
        case 0:
          strcpy(index[reviewCount].name, line);
          break;
        case 1:
          strcpy(index[reviewCount].type, line);
          break;
        case 2:
          strcpy(index[reviewCount].averagePrice, line);
          break;
        case 3:
          strcpy(index[reviewCount].rating,line);
          //printf("Case 3: %d \n", index[reviewCount].rating);
          break;
      }
    }
  }

  search_index = 0;
    printf("\n\n\nEnter the name of the restaurant you want to search for ...\n");
    scanf("%s",entry);
    printf("searching restaurants ....\n\n");
    search(root , entry);

    if(search_index == 0)
        printf("No match found! \n\n");


  for(int i = 0 ; i < totalReviews; i++){
    printf("\n\n\n\nList %d: \nRestaurant: %sType: %sAverage Price: %lf \nRating: %lf\n", i, index[i].name, index[i].type, index[i].averagePrice, index[i].rating);
  }

  //SEARCH(?) and DISPLAY(printf) selected RESTAURANT(index[])

  //SORT ARRAY by NAME(char string) or RATING(int)

  fclose(file);

}

void search(Restaurant *root, char entry[]){
  Restaurant *temp;
  temp = root;

  if(root!=NULL){
    search(root->left , entry);
    if (strstr(root->name,entry)){
      printf("\n\n\n\nList %d: \nRestaurant: %sType: %sAverage Price: %lf \nRating: %lf\n", root, root->name, root->type, root->averagePrice, root->rating);
      search_index = 1;
    }
    search(root->right,entry);
  }

}
Restaurant *RestaurantFind(searchList[], keyword[], int numEntries){

}

//int lookup(struct entry dictionary[], char search[], int entries)

//void printResults(struct *index){

}


int Search_in_File(char *fname, char *str) {
    FILE *fp;
    int line_num = 1;
    int find_result = 0;
    char temp[512];


    while(fgets(temp, 512, fp) != NULL) {
        if((strstr(temp, str)) != NULL) {
            printf("A match found on line: %d\n", line_num);
            printf("\n%s\n", temp);
            find_result++;
        }
        line_num++;
    }

    if(find_result == 0) {
        printf("\nSorry, couldn't find a match.\n");
    }

    //Close the file if still open.
    if(fp) {
        fclose(fp);
    }
    return(0);
}
