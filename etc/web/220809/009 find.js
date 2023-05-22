const arr = [1,2,3,4,5];

//배열의 고차함수 기본형식
// arr.some((element,index,array) => {})
// arr.find((element,index,array)=> {})

console.log(arr.find(element=>element>4))
console.log(arr.findIndex(element=>element>4))