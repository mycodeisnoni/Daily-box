const arr =[1,2,3,4,5];

//console.log(arr.every((element,index,array)=>{return elemenmt>0}))

console.log(arr.every( element => elemenmt>0 ))

// 아래와 같은 역할
let flag =true;
for(let i =0;i<arr.length;i++){
    if(arr[i]<0){
        flag=false;
        break;
    }
}