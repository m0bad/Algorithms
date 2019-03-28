// 1. Finds the smallest value in an array
function find_smallest_number(array){
    var smallest_number=array[0];
    var smallest_index=0;

    for(var i=0;i<array.length;i++){
        if(array[i]<smallest_number){
            smallest_number=array[i];
            smallest_index=i;
        }
    }
    return smallest_index;
}

// 2. Sort the array
function selection_sort(array){
    var sorted_array=[];

    for(int i=0;i<array.length;i++){
        // Finds the smallest element in the array
        var smallest_index=find_smallest_number(array);
        // Adds the smallest element to new array
        sorted_array.push(array.splice(smallest_index,1)[0]);
    }
    return sorted_array;
}
