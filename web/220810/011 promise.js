//new Promise((res,rez)=>{})

const promiseobj = new Promise(resolve=>{
    resolve("첫번째일성공") //얘가 끝나고 나면 then으로 이동
})

// 위 : 성공만 모아둠

const promiseobj2 = new Promise((resolve,reject)=>{
    reject("실패")
})

// 위 : 실패만 모아둠

promiseobj.then(result => {
    console.log(resolt)
})



// promiseobj2.then(null,error => {
//     console.log(error)
// })
// = 이렇게쓸까?
promiseobj2.catch(error => {
    console.log(error)
})

promiseobj.finally(()=>{
    console.log("작업이 끝났어요")
})