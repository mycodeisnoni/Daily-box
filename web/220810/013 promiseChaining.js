// 0이라는 숫자를 초기값으로 갖고있음
// 1회차에는  +1
// 2회차에는 *2
// 3회차에는 +1
// 4회차에는 *2

// 동작은 비동기적으로 하는데 소스코드의 흐름은 동기적으로!

// promise 생성자 함수의 기본 형태
const promise = new Promise((resolve,reject)=>{
    resolve(0)
})

promise.then(data => {return data +1})  //1회차
.then(data => data*2)  // 2회차
.then(data => data+1)  // 3회차
.then(data => data*2)  // 4회차
.then(data => console.log(data))


