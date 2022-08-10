function hello(value){
    console.log(value)
}

const hello2 = value => console.log(value)


//[3,5,4,2].array.forEach(element => {
    
//});

//[3,5,4,2].forEach(요기 안에 들어올 내용은 "callback 함수")



console.log([3,5,4,2].forEach(hello))
console.log([3,5,4,2].forEach(hello2))

//3
//5
//4
//2



const arr = [3,5,4,2] // 이걸 넣게 되면 아래에 console.log가
//무한대로 늘어나도 수정이 편해짐

//console.log(arr.forEach(hello))
//console.log(arr.forEach(hello2))


// 총 3개까지 받을 수 있어요
console.log(arr.forEach((element, index, array) => {
    console.log(element, index, array)
}))