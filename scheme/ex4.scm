(define-syntax stream-cons
    (syntax-rules ()
        ((_ x y) (cons x (delay y)))
    )
)

(define-syntax stream-car
    (syntax-rules ()
        ((_ x) (car x ))
    )
)

(define-syntax stream-cdr
    (syntax-rules ()
        ((_ x) (force (cdr x)))
    )
)

;2からはじまる整数の無限リストを生成する関数
(define numbers 
    (lambda ()
        (letrec (
            (stream
                    (lambda (n) (stream-cons n (stream (+ n 1))))
            )
                )
            (stream 2)
        )
    )
)

;無限リストの先頭から指定された個数の値を取り出す関数
(define head 
    (lambda (n L)
        (if (<= n 0) '()
            (cons (stream-car L) (head (- n 1) (stream-cdr L)))
        )
    )
)

(define screen
    (lambda (num L)
        (if (= (modulo (stream-car L) num) 0) (screen num (stream-cdr L))
            (stream-cons (stream-car L) (screen num (stream-cdr L))) ;else(割り切れない時)
        )
    )
)

(define EraList
    (lambda (L)
        (stream-cons (stream-car L) (EraList(screen (stream-car L) (stream-cdr L))))
    )
)

(define Eratosthenes
    (lambda (N)
        (cond   ((= N 0) '())
                ((= N 1) '(2))
                (else (head N (EraList(numbers))))
        )
    )
)

(Eratosthenes 3)
(Eratosthenes 10)
(Eratosthenes 3000)

