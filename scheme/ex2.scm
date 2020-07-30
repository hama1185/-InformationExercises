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