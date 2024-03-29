print("lmao")

vim.wo.number = true
vim.wo.rnu = true
vim.bo.tabstop=4
vim.bo.shiftwidth=4
vim.bo.expandtab = true

local keymap = vim.api.nvim_set_keymap

local Plug = vim.fn['plug#']

vim.call('plug#begin')

Plug 'nvim-treesitter/nvim-treesitter'

Plug 'dhruvasagar/vim-table-mode'

Plug 'chrisbra/unicode.vim'

Plug 'turbio/bracey.vim' 

Plug 'mattn/emmet-vim'

Plug 'norcalli/nvim-colorizer.lua'

Plug 'preservim/nerdtree'

vim.call('plug#end')

require'nvim-treesitter.configs'.setup {
  -- A list of parser names, or "all"
  ensure_installed = { "bash", "c", "c_sharp", "cpp", "markdown", "lua", "rust", "html", "css", "javascript" },

  -- Install parsers synchronously (only applied to `ensure_installed`)
  sync_install = false,

  -- Automatically install missing parsers when entering buffer
  -- Recommendation: set to false if you don't have `tree-sitter` CLI installed locally
  auto_install = true,

  -- List of parsers to ignore installing (for "all")
  ignore_install = { "" },

  ---- If you need to change the installation directory of the parsers (see -> Advanced Setup)
  -- parser_install_dir = "/some/path/to/store/parsers", -- Remember to run vim.opt.runtimepath:append("/some/path/to/store/parsers")!

  highlight = {
    -- `false` will disable the whole extension
    enable = true,

    -- NOTE: these are the names of the parsers and not the filetype. (for example if you want to
    -- disable highlighting for the `tex` filetype, you need to include `latex` in this list as this is
    -- the name of the parser)
    -- list of language that will be disabled
    disable = {},
    -- Or use a function for more flexibility, e.g. to disable slow treesitter highlight for large files
    disable = function(lang, buf)
        local max_filesize = 100 * 1024 -- 100 KB
        local ok, stats = pcall(vim.loop.fs_stat, vim.api.nvim_buf_get_name(buf))
        if ok and stats and stats.size > max_filesize then
            return true
        end
    end,

    -- Setting this to true will run `:h syntax` and tree-sitter at the same time.
    -- Set this to `true` if you depend on 'syntax' being enabled (like for indentation).
    -- Using this option may slow down your editor, and you may see some duplicate highlights.
    -- Instead of true it can also be a list of languages
    additional_vim_regex_highlighting = false,
  },
}

keymap('n', '<S-l>', '<Cmd>update | !pdflatex -interaction=batchmode main.tex<CR>', {noremap = true})
keymap('n', '<S-m>', '<Cmd>update | !make<CR>', {noremap = true})
keymap('n', '<S-t>', '<Cmd>NERDTreeToggle<CR>', {noremap = true})
keymap('n', '<S-Left>', '<Cmd>NERDTreeFocus<CR>', {noremap = true})
keymap('n', '<S-Right>', '<Cmd>wincmd w<CR>', {noremap = true})
