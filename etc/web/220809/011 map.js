const arr = [1,2,3,4,5];

//배열 고차함수의 기본형태
// arr.some((element,index,array) => {return console.log(element)})


arr.forEach((element,index,array)=>{
    return console.log(element);
})



const a = arr.forEach(element => console.log(element))
const b = arr.map(element => console.log(element));
console.log(a)
console.log(b)




// forEach 는 항상 반환값이 undefined
// map 은 반환값이 있음
```const newarr = []
arr.forEach(element => newarr.push(element*2))
console.log(newarr)```
const newarr = arr.map(element => element *2)


