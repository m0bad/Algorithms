function find_sum(arr){
    if (arr.length ===0)
        return 0;
    else if(arr.length === 1)
        return arr[0];
    return arr[0] + find_sum(arr.slice(1,arr.length));
}

var arr =[10,20,5,5,2,8,10];  // sum is 60

console.log(find_sum(arr)); //60
