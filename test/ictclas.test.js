var ictclas = require('../index.js');

describe('ictclas', function() {
    describe('#wordFreqStat()', function() {
        var wft = ictclas.wordFreqStat;
        it('接受一个参数', function() {
            try {
                wft('哈尔滨', 1);
            } catch (e) {
                // console.log(e.message);
            }
        });
        it('参数类型为字符串类型', function() {
            try {
                wft(1);
            } catch (e) {
                // console.log(e.message);
            }
        });
        it('返回结果为字符串，例如："哈尔滨/ns/1#天气/n/1#不错/a/1#"', function() {
            wft('哈尔滨天气不错').should.equal('哈尔滨/ns/1#天气/n/1#不错/a/1#');
        });
        it('返回结果中包含词性，例如："/ns"表示地理名词', function() {
            wft('哈尔滨天气不错').indexOf('/ns').should.not.equal(-1);
        });
        it('词语之间用#进行分隔，例如："哈尔滨/ns/1#天气/n/1"中，哈尔滨和天气用字符"#"进行分隔', function() {
            wft('哈尔滨天气不错').indexOf('#').should.not.equal(-1);
        });
        it('返回结果中包含词频，例如："哈尔滨/ns/1"表示结果字符串中包含一个\"哈尔滨\"名词', function() {
            var result = wft('哈尔滨天气不错');
            result.charAt(result.indexOf('#') - 1).should.not.equal('/');
        });
    })
});
