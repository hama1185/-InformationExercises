(define alphabet
  (read (open-input-file "/class/scheme/alphabet")))

(define tokugawa
  (read (open-input-file "/class/scheme/tokugawa")))

(define get-depth
  (lambda (tree n)
    (if (> n 0)
      (apply append (map (lambda (t) (get-depth t (- n 1))) (cdr tree)))
      (list(car tree))
    )
  )
)
(get-depth alphabet 1)
(get-depth alphabet 3)
(get-depth tokugawa 1)
(get-depth tokugawa 3)
(get-depth tokugawa 6)

(define search
  (lambda (tree key n)
    (if (equal? (car tree) key)
      n
      (if (null? (cdr tree))
        0
        (apply + (cons 0 (map (lambda (t) (search t key (+ n 1))) (cdr tree))))
      )
    )
  )
)

(define get-cousin
  (lambda (tree key)
    (get-depth tree (search tree key 0))
  )
)

(get-cousin alphabet 'b3)
(get-cousin alphabet 'e1)
(get-cousin tokugawa '秀忠)
(get-cousin tokugawa '吉宗)
(get-cousin tokugawa '家継)

(define get-path
  (lambda (tree key)
    (cond ((null? tree) '())
          ((equal? (car tree) key) (list key))
          ((equal? (car tree) '()) '())
          (else
            (let (
                (marge (apply append (map (lambda (t) (get-path t key)) (cdr tree))))
              )
              
              (if (null? marge)
                  '()
                  (cons (car tree) marge)
              )
              
            ) 
          )
    )
  )
)

(get-path alphabet 'c9)
(get-path alphabet 'e3)
(get-path tokugawa '家光)
(get-path tokugawa '家治)
(get-path tokugawa '家慶)