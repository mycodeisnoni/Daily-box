const arr = [1,2,3,4,5];

```arr.some((element)=>{
    return element > 3
    // return문의 경우 식이 하나면 return, {} 생략가능
})```


console.log(arr.some(element=> element > 3))
// 하나라도 있으면 true 반영

//아래랑 같은 역할
let flag = false;
for(let i =0; i<arr.length;i++){
    if(arr[i]>3){
        flag = true;
        break;
    }
}
console.log(flag);