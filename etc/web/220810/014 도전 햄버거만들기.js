const promise = new Promise((resolve,reject)=>{
    resolve("")
})

promise.then((data)=>{
    data + "참깨빵 위에"
})
.then((data)=>console.log(data))