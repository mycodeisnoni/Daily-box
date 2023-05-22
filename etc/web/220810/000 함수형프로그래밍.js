// 매개변수로 숫자 하나 (input)을 받아서
// 받은 input에 +1을 하여 리턴하는 화살표 함수


const increament = input => input + 1
const decreament = input => input - 1
const squared = input => input * input
const half = input => input / 2 


//javasccript 는 배열 안에 함수 가능
const arr = [increament, decreament, increament, increament, decreament, squared, squared, half, increament]

arr.reduce((acc,cur)=>{
    cur(acc)
    return acc;
},1)