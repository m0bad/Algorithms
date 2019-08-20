var arr =[10,20,5,5,2,8,10];  // 7

function count_arr(arr){
    if (arr.length === 0)
        return 0;
    else if (arr.length ===1)
        return 1;
    return 1 + count_arr(arr.slice(1,arr.length));
}

console.log(count_arr(arr));
