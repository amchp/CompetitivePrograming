struct node{
    int v, tl, tr, lft, rgt;
    int val;
    int lazy;
    bool hlazy;
    node(){}
    node(int v, int tl, int tr, int val, int lft, int rgt): v(v), tl(tl), tr(tr), val(val), lft(lft), rgt(rgt){}
};

struct stree{
  int n, l, r, val, neutro = 0;
  vector<node> t;
  stree(int mn, int mx): n(n){
    t.pb(node(0, mn, mx, 0, -1, -1));
    t[0].lazy = 0;
    t[0].hlazy = true;
  }
  inline int oper(int a, int b){ return a > b ? a : b; }
  inline void oper_push(int v, int& psh, bool lft){
    int& tl = t[v].tl;
    int& tr = t[v].tr;
    int& lazy = t[v].lazy;
    int tm = (1LL*tl + tr) >> 1;
    if(psh == -1){
      psh = sz(t);
      if(lft){
        t.pb(node(psh, tl, tm, lazy, -1, -1));
      }else{
        t.pb(node(psh, tm + 1, tr, lazy, -1, -1));
      }
    }
    t[psh].val = max(t[psh].val, lazy);
    t[psh].hlazy = true;
    t[psh].lazy = max(t[psh].lazy, lazy);
  }
  inline void push(int v){
    if(t[v].hlazy){
      int& lft = t[v].lft;
      int& rgt = t[v].rgt;
      oper_push(v, lft, true);
      oper_push(v, rgt, false);
    }
    t[v].hlazy = false;
  }
  void upd(int v){
    int& tl = t[v].tl;
    int& tr = t[v].tl;
    if(tl > r || tr < l) return;
    if(l <= tl && tr <= r){
      t[v].val = max(t[v].val, val);
      t[v].lazy = val;
      t[v].hlazy = true;
      return ;
    }
    push(v);
    int lft = t[v].lft, rgt = t[v].rgt;
    upd(lft);  upd(rgt);
    t[v].val = oper(t[lft].val, t[rgt].val);
  }
  int query(int v){
    int& tl = t[v].tl, tr = t[v].tr;
    // d(tl);
    // d(tr);
    if(tl > r || tr < l) return neutro;
    if(l <= tl && tr <= r) return t[v].val;
    push(v);
    int lft = t[v].lft, rgt = t[v].rgt;
    return oper(query(lft), query(rgt));
  }
  void update(int ql, int qr, int qval){  
    l = ql, r = qr, val = qval, upd(0); }
  int query(int ql, int qr){ l = ql, r = qr;
  // d(l);
  // d(r);
  return query(0); }
};
