(define alphabet
  (read (open-input-file "./w2/alphabet")))

(define tokugawa
  (read (open-input-file "./w2/tokugawa")))

(define get-depth
  (lambda (tree n)
    (if (> n 0)
      (apply append (map (lambda (t) (get-depth t (- n 1))) (cdr tree)))
      (list(car tree))
    )
  )
)

(define search
  (lambda (tree key n)
    (if (equal? (car tree) key)
      '(n)
      (if (null? (cdr tree))
        '(0)
        (apply append (map (lambda (t) (search t key (+ n 1))) (cdr tree)))
      )
    )
  )
)

(define get-cousin
  (lambda (tree key)
    (search tree key 0)
  )
)