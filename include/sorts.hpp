#include <stdio.h>

#ifndef quicksort_h
#define quicksort_h

/*/ Quicksort to sort Players
void swapPlayers(Player *a, Player *b)
{
    Player t = *a;
    *a = *b;
    *b = t;
}

float partitionPlayers(Player arr[], int low, int high)
{
    Player pivotPlayer = arr[high];
    float pivot = pivotPlayer.globalRating(); 
    int i = (low - 1);                        

    for (int j = low; j <= high - 1; j++)
    {
        Player player = arr[j];
        if (player.globalRating() <= pivot)
        {
            i++;
            swapPlayers(&arr[i], &arr[j]);
        }
    }
    swapPlayers(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSortPlayers(Player arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partitionPlayers(arr, low, high);
        quickSortPlayers(arr, low, pi - 1);
        quickSortPlayers(arr, pi + 1, high);
    }
}
*/
// Quicksort to sort User Ratings
void swapRatings(Info *a, Info *b){
    Info t = *a;
    *a = *b;
    *b = t;
}

float partitionRatings(Info arr[], int low, int high){
    Info pivotRating = arr[high];
    float pivot = pivotRating.rating; 
    int i = (low - 1);                

    for (int j = low; j <= high - 1; j++){
        Info Info = arr[j];
        if (Info.rating <= pivot){
            i++;
            swapRatings(&arr[i], &arr[j]);
        }
    }
    swapRatings(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSortRatings(Info arr[], int low, int high){
    if (low < high){
        int pi = partitionRatings(arr, low, high);
        quickSortRatings(arr, low, pi - 1);
        quickSortRatings(arr, pi + 1, high);
    }
}

#endif