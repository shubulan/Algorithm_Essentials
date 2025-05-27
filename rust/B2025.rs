
fn main() {
    for i in 0..5 {
        let s = (i - 2_i32).abs();
        for _ in 0..s  {
            print!(" ");
        }
        let t = 5 - 2 * s;
        for _ in 0..t {
            print!("*");
        }
        println!("");
    }
}