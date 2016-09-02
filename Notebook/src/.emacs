(package-initialize)

(add-hook 'c++-mode-hook (lambda () (setq-default flycheck-gcc-language-standard "c++11")))
(add-hook 'after-init-hook #'global-flycheck-mode)

;; show line numbers
(global-linum-mode t)

;; show bracket and parenthesis matching
(show-paren-mode 1)

