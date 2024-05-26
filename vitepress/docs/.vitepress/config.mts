import { defineConfig } from 'vitepress'
import markdownItKatex from 'markdown-it-katex'
// https://vitepress.dev/reference/site-config
export default defineConfig({
  title: "shubulan's algorithm route",
  description: "algorithm template",
  base: "/Algorithm_Essentials/",
  markdown: {
    lineNumbers: true,
    config: (md) => {
      md.use(markdownItKatex)
    }
  },
  themeConfig: {
    // https://vitepress.dev/reference/default-theme-config
    nav: [
      { text: '知识点', link: '/contents/' },
      { text: '面试通关', link: '/interview/' }
    ],

    sidebar: {
      '/contents/': [
        {
          text: '基本介绍',
          collapsed: true,
          items: [
            { text: '项目介绍', link: '/contents/index' },
            { text: '算法认知', link: '/contents/introduction' },
          ]
        },
        {
          text: '穷竭枚举',
          collapsed: true,
          items: [
            { text: '循环枚举', link: '/contents/ch00/for_while_loop' },
            { text: '深度优先：递归与回溯', link: '/contents/ch00/dfs' },
            { text: '指数型枚举', link: '/contents/ch00/exponential_enumeration'},
            { text: '组合型枚举', link: '/contents/ch00/combinatorial_enumeration'},
            { text: '排列型枚举', link: '/contents/ch00/permutation_enumeration'},
            { text: '深度优先：暴力搜图', link: '/contents/ch00/dfs'},
            { text: '广度优先：无权图的最短路', link: '/contents/ch00/bfs'},
          ]
        },
        {
          text: '基本思想',
          collapsed: true,
          items: [
            { text: '顺序', link: '/contents/ch01/sort' },
            { text: '递归与分治', link: '/contents/ch01/binary_search' },
            { text: '二分算法', link: '/contents/ch01/binary_search' },
          ]
        },
        {
          text: '常用技巧与代码能力提升',
          collapsed: true,
          items: [
            { text: '前缀和与差分', link: '/contents/ch02/presum_diff' },
            { text: '思维题', link: '/contents/ch02/think_problem' },
            { text: '双指针', link: '/contents/ch02/two_pointer' },
            { text: '位运算', link: '/contents/ch02/bitwise_operation' },
            { text: '离散化', link: '/contents/ch02/discretization' },
            { text: '模拟', link: '/contents/ch02/' },
            { text: '构造', link: '/contents/ch02/make_up.md' },
          ]
        },
        {
          text: '数据结构',
          collapsed: true,
          items: [
            { text: '简单数据结构', link: '/contents/ch03/data_structure_I' },
            { text: '数据结构进阶 I', link: '/contents/ch03/data_structure_II' },
            { text: '单调栈与单调队列', link: '/contents/ch03/monotonic_queue_stack' },
          ]
        },
        {
          text: '搜索技巧与图论',
          collapsed: true,
          items: [
            { text: '最短路径', link: '/contents/ch04/shortest_path' },
          ]
        },
        {
          text: '数学',
          collapsed: true,
          items: [
            { text: '基本数学问题', link: '/contents/ch05/README' },
            { text: '高精度计算', link: '/contents/ch05/bignum' },
            { text: '计算几何', link: '/contents/ch05/bignum' },
          ]
        },
        {
          text: '动态规划',
          collapsed: true,
          items: [
            { text: '介绍', link: '/contents/ch06/introduction' },
            { text: '背包问题', link: '/contents/ch06/knanpsack_problem' },
            { text: '线性dp', link: '/contents/ch06/linear_dp.md' },
            { text: '记忆化搜索', link: '/contents/ch06/memo_search' },
            { text: '区间dp', link: '/contents/ch06/interval_dp.md' },
            { text: '状压dp', link: '/contents/ch06/bitwise_dp' },
            { text: '计数dp', link: '/contents/ch06/count_dp' },
            { text: '数位dp', link: '/contents/ch06/digital_dp' },
            { text: '树形dp', link: '/contents/ch06/tree_dp' },
            { text: '状态机 dp', link: '/contents/ch06/state_machine_dp' },
            { text: 'DAG dp', link: '/contents/ch06/DAG_dp' },
            { text: '进阶：环形dp', link: '/contents/ch06/loop_dp' },
          ]
        },
        {
          text: '贪心算法',
          collapsed: true,
          items: [
            { text: '贪心思想', link: '/contents/ch07/README' },
          ]
        },
        {
          text: '高级数据结构',
          collapsed: true,
          items: [
            { text: '线段树', link: '/contents/ch08/seg_tree' },
            { text: '分块算法', link: '/contents/ch08/blocks' },
          ]
        },
        {
          text: '高级图论',
          collapsed: true,
          items: [
            { text: '二分图', link: '/contents/ch09/README' },
          ]
        },
        {
          text: '动态规划进阶',
          collapsed: true,
          items: [
            { text: '空', link: '/contents/ch02/sort' },
          ]
        },
        {
          text: '计算几何',
          collapsed: true,
          items: [
            { text: '计算几何', link: '/contents/ch11/README' },
          ]
        },
        {
          text: '附录',
          collapsed: true,
          items: [
            { text: '不常用算法', link: '/contents/appendix/README' },
          ]
        }
      ],
      '/interview/': [
        {
          text: '穷竭枚举',
          collapsed: true,
          items: [
            { text: '循环枚举', link: '/markdown-examples' },
            { text: '深度优先搜索', link: '/api-examples' },
            { text: '广度优先搜索', link: '/appendix'},
            { text: '指数型枚举', link: '/appendix'},
            { text: '组合型枚举', link: '/appendix'},
            { text: '排列型枚举', link: '/appendix'}
          ]
        }
      ]
    },

    socialLinks: [
      { icon: 'github', link: 'https://github.com/shubulan' }
    ]
  }
})
