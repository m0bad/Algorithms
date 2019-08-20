//the steps to do quick sort are:
    // 1. Pick a pivot.
    // 2. Partition the array into two sub-arrays: elements less than the pivotand elements greater than the pivot.
    // 3. Call quicksort recursively on the two sub-arrays.

function quick_sort(arr){
    //base case
    if (arr.length < 2)
        return arr;
    //recursive case
    //step 1
    var pivot = arr[0];
    //step 2
    var less = arr.slice(1).filter(number => number <= pivot);
    var greater = arr.slice(1).filter(number => number > pivot);
    //step 3
    return quick_sort(less).concat([pivot],quick_sort(greater));
}
var arr=[1,4,6,92,100,65,243,1000];
console.log(quick_sort(arr));  //[ 1, 4, 6, 65, 92, 100, 243, 1000 ]
