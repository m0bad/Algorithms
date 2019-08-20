function binary_search(list,item){
    let low=0;
    let high=(list.length)-1;

    while(low<=high){
        let mid=Math.floor((low+high)/2)
        if(mid === item){
            return mid;
        }
        if(item>mid){
            low=mid+1;
        }else {
            high =mid-1;
        }
    }
    return null;
}


const list=[1,2,3,4,5,6,7,8,9,10];
console.log(binary_search(list,8));//8
console.log(binary_search(list,12));//null
