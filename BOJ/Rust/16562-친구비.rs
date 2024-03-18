use std::io::{Read};

fn find(n: i32, p: &mut [i32]) -> i32 {
    if n == p[n as usize] {
        return n;
    } else {
        p[n as usize] = find(p[n as usize], p);
        return p[n as usize];
    }
}

fn merge(n1: i32, n2: i32, p: &mut [i32], a: &mut [i32]) {
    let p1 = find(n1, p);
    let p2 = find(n2, p);

    if a[p1 as usize] > a[p2 as usize] {
        p[p1 as usize] = p2;
    } else {
        p[p2 as usize] = p1;
    }
}

fn main() {
    let mut p: [i32; 10_010] = [0; 10_010];
    let mut a: [i32; 10_010] = [0; 10_010];
    let mut s = String::new();

    std::io::stdin().read_to_string(&mut s).unwrap();

    let mut buffer = s.split_whitespace();

    let student_cnt = buffer.next().unwrap().parse::<i32>().unwrap();
    let m = buffer.next().unwrap().parse::<i32>().unwrap();
    let money = buffer.next().unwrap().parse::<i32>().unwrap();

    for i in 1..n + 1 {
        p[i as usize] = i;
        a[i as usize] = buffer.next().unwrap().parse::<i32>().unwrap();
    }

    for _i in 0..m {
        let u = buffer.next().unwrap().parse::<i32>().unwrap();
        let v = buffer.next().unwrap().parse::<i32>().unwrap();
        merge(u, v, &mut p, &mut a);
    }

    let mut fee = 0;
    for i in 1..n + 1 {
        if p[i as usize] == i {
            fee += a[i as usize];
        }
    }

    if fee <= k {
        println!("{fee}");
    } else {
        println!("Oh no");
    }
}