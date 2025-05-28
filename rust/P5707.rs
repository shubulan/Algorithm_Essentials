
use std::io;
use std::str::FromStr;

fn main() {
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    input = input.trim().to_string();
    let v: Vec<&str> = input.split_ascii_whitespace().collect();
    let v: Vec<f64> = v.into_iter().map(|x| f64::from_str(x).unwrap()).collect();
    let (s, v) = (v[0], v[1]);
    let mut x = (s / v).ceil() as i64;
    x += 10;
    let h = x / 60;
    if h >= 24 {
        println!("08:00");
        return;
    }
    let m = x % 60;
    let h = ((7 - h) % 24 + 24) % 24;
    println!("{:02}:{:02}", h, 60 - m);
}