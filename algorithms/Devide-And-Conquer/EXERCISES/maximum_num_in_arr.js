function find_max(arr){
    if(arr.length === 2)
        return Math.max(arr[0],arr[1]);
    return Math.max(arr[0],find_max(arr.slice(1,arr.length)));
}
var arr =[10,20,5,5,2,8,10,100];  //100

console.log(find_max(arr)); //100
