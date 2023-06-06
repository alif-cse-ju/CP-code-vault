fn main() {
    proconio::input! {
        n: usize,
        a: [u32; n],
    }
    let ans = (0..).find(|x| !a.contains(&x)).unwrap();
    println!("{}", ans);
}
