use std::io;
fn main() {
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let c = input.chars().nth(0).unwrap();
    let mut s = String::new();
    s.push(c);
    println!("  {}", s);
    s.push(c); s.push(c);
    println!(" {}", s);
    s.push(c); s.push(c);
    println!("{}", s)
}