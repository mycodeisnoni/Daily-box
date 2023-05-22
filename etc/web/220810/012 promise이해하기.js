console.log("점원:어서오세요")
console.log("점원:주문하시겠어요?")
console.log("손님:잠시만요")
console.log("점원:결정되면 불러주세요")



const Promise = new Promise((resolve,reject) => {
    setTimeout(() => {
        console.log("손님: 저 이제 주문할게요!")
        reject("저 그냥 다른데서 먹을게요")
    }, 3000);
})


promiseobj.then((menu)=>{
    console.log(menu)
    console.log("GOOD")
}).catch(()=> {
    console.log("OH NO")
})

console.log("다른 일 다른 일 다른 일")