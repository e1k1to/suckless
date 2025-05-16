print("lmao")

vim.wo.number = true
vim.wo.rnu = true
vim.bo.tabstop=4
vim.bo.shiftwidth=4
vim.bo.expandtab = true

local keymap = vim.api.nvim_set_keymap

local Plug = vim.fn['plug#']

vim.call('plug#begin')

Plug 'dhruvasagar/vim-table-mode'

Plug 'chrisbra/unicode.vim'

Plug 'turbio/bracey.vim' 

Plug 'mattn/emmet-vim'

Plug 'norcalli/nvim-colorizer.lua'

Plug 'preservim/nerdtree'

vim.call('plug#end')

keymap('n', '<S-l>', '<Cmd>update | !pdflatex -interaction=batchmode main.tex<CR>', {noremap = true})
keymap('n', '<S-m>', '<Cmd>update | !make<CR>', {noremap = true})
keymap('n', '<S-t>', '<Cmd>NERDTreeToggle<CR>', {noremap = true})
keymap('n', '<S-Left>', '<Cmd>NERDTreeFocus<CR>', {noremap = true})
keymap('n', '<S-Right>', '<Cmd>wincmd w<CR>', {noremap = true})
